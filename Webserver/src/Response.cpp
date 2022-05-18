#include "Response.hpp"

Response::Response(const Response &src)
{
	*this = src;
	return;
}

Response &Response::operator=(const Response &rhs)
{
	if (this != &rhs)
	{
		_response = rhs._response;
		_content_type = rhs._content_type;
		_buffString = rhs._buffString;
	}
	return *this;
}

std::string cast_int_to_string(size_t len)
{
	std::stringstream ss;

	ss.clear();
	ss << len;
	std::string length = "Content-length: " + ss.str();
	ss.clear();

	return (length);
}

void Response::read_buf(std::ifstream &file)
{
	std::stringstream _buff;

	_buff << file.rdbuf();
	_buffString = _buff.str();
	_buff.clear();
}

int Response::check_errors(Request request, Server &serv, bool cgi)
{
	// check on client_max_body_size
	if (request.getContentLen() != 0 && request.getContentLen() > serv.getMaxSize())
	{
//		std::cout << RED << "here" << END << std::endl;
		error(serv);
		return (1);
	}

	int fl = 0;	 // проверка на методы
	for (size_t i = 0; i < request.getLocationReq().getMethods().size(); i++) // i - number methods in parse
	{
		if (request.getLocationReq().getMethods()[i] == request.getMethod())
			fl = 1;
	}
	if (fl == 0) // if method not in config
	{
//		std::cout << RED << "NOT FIND METHOD" << END << std::endl;
		_response = "HTTP/1.1 405 Method Not Allowed\r\n"+ _content_type + "\r\n\r\n<h1>405 "
																		"Method Not Allowed</h1>\r\n";
		return (1);
	}

	size_t a = request.getVersion().find("1.1"); // check version
	if (a == std::string::npos)
	{
		error(serv);
		return (1);
	}
	if (check_path(request, cgi) && request.getMethod() != "POST") // check right path
	{
		error(serv);
		return (1);
	}
	return (0);
}

std::vector<std::string> Response::ft_split(std::string str)
{
	std::vector<std::string> res;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (std::isspace(str[i]))
		{
			if (i == j)
				++j;
			else
			{
				res.push_back(std::string(str, j, i - j));
				j = i + 1;
			}
		}
		++i;
	}
	if (i != j)
		res.push_back(std::string(str, j, i - j));
	return (res);
}

size_t Response::ft_lines(std::string source)
{
	size_t i;
	size_t lines;

	i = 0;
	lines = 1;
	while (source[i])
	{
		if (source[i++] == '\n')
			++lines;
	}
	return (lines);
}

std::string Response::ft_getline(std::string source, size_t n)
{
	size_t i;
	size_t j;
	size_t line_count;

	if (n >= ft_lines(source))
		return (std::string());
	line_count = 0;
	i = 0;
	while (line_count < n)
	{
		if (source[i++] == '\n')
			++line_count;
	}
	while (std::isspace(source[i]) && source[i] != '\n')
		++i;
	j = 0;
	while (source[i + j] && source[i + j] != '\n')
		++j;
	while (j > 0 && std::isspace(source[i + j - 1]))
		--j;
	return (std::string(source, i, j));
}

std::string Response::ft_timestamp(time_t timestamp)
{
	char buffer[33];
	struct tm *ts;
	size_t last;

	ts   = localtime(&timestamp);
	last = strftime(buffer, 32, "%a, %d %b %Y %T GMT", ts);
	buffer[last] = '\0';
	return (std::string(buffer));
}

std::string Response::CGIDateHeader(void)
{
	struct timeval now;
	struct timezone tz;

	gettimeofday(&now, &tz);
	return (ft_timestamp(now.tv_sec + tz.tz_minuteswest * 60));
}

std::string Response::CGIStatus(std::string response)
{
	std::vector<std::string> splits;

	for (size_t i = 0; i < ft_lines(response); ++i)
	{
		splits = ft_split(ft_getline(response, i));
		if (splits.size() == 3 && splits[0] == "Status:")
			return (splits[1] + " " + splits[2]);
	}
	return ("");
}

std::string Response::CGIHeaders(std::string response)
{
	std::string res;
	size_t size;
	int header_char_count = 0;

	std::string headers = response;
	if (response.find("\r\n\r\n") != std::string::npos)
		headers = response.substr(0, response.find("\r\n\r\n"));
	// std::cout << "headers.length(): " << headers.length() << std::endl;
	if (headers != "")
	{
		for (size_t i = 0; i < headers.length(); i++)
			if (headers[i] != '\n' && headers[i] != '\r')
				header_char_count++;
	}
	// std::cout << "header_char_count: " << header_char_count << std::endl;
	// std::cout << "response.size(): " << response.size() << std::endl;
	// std::cout << "std::count(response.begin(), response.end(), '\\n'): " << std::count(response.begin(), response.end(), '\r') << std::endl;
	// std::cout << "std::count(response.begin(), response.end(), '\\r'): " << std::count(response.begin(), response.end(), '\r') << std::endl;

	size = response.size() - std::count(response.begin(), response.end(), '\r') - std::count(response.begin(), response.end(), '\r') - header_char_count;
	// std::cout << "size: " << size << std::endl;

	res = response;
	res = "Content-Length: " + std::to_string(size) + "\r\n" + res;
	res = "Date: " + CGIDateHeader() + "\r\n" + res;
	if (CGIStatus(response).size() > 0)
		res = "HTTP/1.1 " + CGIStatus(response) + "\r\n" + res;
	else
		res = "HTTP/1.1 200 OK\r\n" + res;
	return (res);
}

void Response::CGIHandler(Request request, Server server, std::string cgiPath) {
	// std::string cgiPath;

	// cgiPath = request.getLocationReq().getRoot();
	// std::cout << "cgiPath: " << cgiPath << std::endl;
	// std::cout << cgiPath + request.getLocationReq().getCGI() << std::endl;
	// заменить на CGI_path из конфиг-файла
	// std::cout << "getCGI: " << request.getLocationReq().getCGI() << std::endl;
	// /Users/robert_zin/Documents/42Cursus/14_webserv/webserv/pages/cgi-bin/cgi_tester
	_response = CGI(cgiPath, request.getLocationReq().getRoot(), request, server, request.getLocationReq()).getOutput();
//	 std::cout << "Response before: " << std::endl;
//	 std::cout << GREEN << _response << END << std::endl;

	_response = CGIHeaders(_response);
//	 std::cout << "Response after: " << std::endl;
//	 std::cout << GREEN << _response << END << std::endl;
}

void Response::prepareResp(Request request, Server &serv)
{
	int			posA = -1;
	int			posB = -1;
	bool		cgi = false;
	std::string	cgiPath;
	std::string	cgiQuery;

	if ((posA = request.getPath().find(".cgi")) > 0 || (posA = request.getPath().find(".bla")) > 0)
		cgi = true;
	if (check_errors(request, serv, cgi))
		return;
	defineContType(request);
	if (cgi) {
		if ((posB = request.getPath().find('?')) > 0)
			cgiPath = request.getPath().substr(0, posB);
		else
			cgiPath = request.getPath();
		if (cgiPath.find(".bla") != std::string::npos)
			cgiPath = "/Users/robert_zin/Documents/42Cursus/14_webserv/webserv/pages/cgi-bin/cgi_tester";
		// std::cout << GREEN << "CGI found: \"" << request.getPath().substr(posA, request.getPath().size() - 1) << "\"" <<  END << std::endl;
		// std::cout << GREEN << "CGI path: \"" << cgiPath << "\"" <<  END << std::endl;
		CGIHandler(request, serv, cgiPath);
	}

	else if (request.getMethod() == "GET")
		fGet(request);
	 else if (request.getMethod() == "POST")
	 	fPost(request, serv);
	else if (request.getMethod() == "DELETE")
		fDelete(request, serv);
	else
		std::cout << "Unknown method" << std::endl;
		// fUnknown();
}

int Response::fPost(Request & request, Server & serv)
{
	std::ofstream out;

	out.open(request.getPath(), std::ios::app);
	if (out.is_open() == 0)
	{
		_response = status404;
		error(serv);
		return (1);
	}

	out << request.getBody();
	out.close();
	_response = status200 + cast_int_to_string(request.getContentLen()) + "\r\n" + _content_type + "\r\n\r\n";

	return (0);
}

void Response::error(Server &serv)
{
//	std::cout << "WE FIND ERROR" << std::endl;
	std::map<int, std::string> map = serv.getErrorPage();
	std::map<int, std::string>::iterator It = map.begin();
	size_t i = It->second.find(".html");
	if (i != std::string::npos) // if we find html extension
	{
//		std::cout << "WE FIND HTML " << It->first << std::endl
//				<< It->second << std::endl;
		std::ifstream file(It->second);
		if (file.is_open() == 0) // ?
		{
			_response = status404;
			return;
		}

		read_buf(file);
		file.close();

		_response = status404 + cast_int_to_string(_buffString.size()) + "\r\n" + "Connection: close" +
				"\r\n" + _content_type + "\r\n" + "\r\n" + _buffString;
	}
	else // else we go to redirect (error redirect on config)
	{
//		std::cout << NEW << "WE REDIRECT" << END << std::endl;
		std::map<int, std::string> map2 = serv.getErrorPage();
		std::map<int, std::string>::iterator im = map2.begin();
//		std::cout << RED << im->second <<END<< std::endl;
		_response = "HTTP/1.1 301 Moved Permanently\r\nLocation: " + im->second;
	}
}

void Response::change_path_autoindex(std::string & res, struct dirent *entry, std::string change)
{
	res += "<a class=\'link\' href=\'" + change + "\'>" + entry->d_name + "</a><br>\n";
}

int Response::go_autoindex(Request &request)
{
	DIR *dir;
	struct dirent *entry;
	std::string res;

	dir = opendir(request.getPath().c_str());
	if (!dir)
		return (1);

	res = "<!DOCTYPE html>\n"
		"<html lang=\"en\">\n"
		"\n"
		"<head>\n"
		"\t<meta charset=\"UTF-8\">\n"
		"\t<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n"
		"\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
		"\t<title>Webserv</title>\n"
		"<style>\n"
		".wrap { margin: 30px;}\n"
		"</style>\n"
		"\n"
		"</head>\n"
		"\n"
		"<body>\n"
		"<h1>Autoindex</h1>\n"
		"<hr>\n"
		"<div class=\'wrap\'>\n";

	while ((entry = readdir(dir)) != nullptr)
	{
		if (std::string(entry->d_name) == ".")
			continue;
		if (std::string(entry->d_name) == "..")
		{
			size_t a = request.getReqPath().find_last_of("/");
			if (a == 0)
				change_path_autoindex(res, entry, std::string(entry->d_name));
			else
				change_path_autoindex(res, entry, request.getReqPath().erase(a, request.getReqPath().length()));
		}
		else if (request.getReqPath() == "/")
			change_path_autoindex(res, entry, std::string(entry->d_name) );
		else
			change_path_autoindex(res, entry, request.getReqPath() + "/" + entry->d_name);
	}
	res += "</div>\n</body>\n"
		"\n"
		"</html>";

	_response = status200 + cast_int_to_string(res.length()) + "\r\n" + _content_type + "\r\n\r\n" + res;
	closedir(dir);
	return (0);
}

void Response::fGet(Request &request)
{
	if (!request.getLocationReq().getRedirect().empty()) // if exist redirect then go there
	{
//		std::cout << NEW << "WE REDIRECT" << END << std::endl;

		_response = "HTTP/1.1 301 Moved Permanently\r\nLocation: " + request.getLocationReq().getRedirect() + "\r\n\r\n";
//		std::cout << RED << _response << END << std::endl;
		return ;
	}
	if (request.getLocationReq().getAutoIndex() == true)
	{
		if (!go_autoindex(request))
			return;
	}

	_response = status200 + cast_int_to_string(_buffString.size()) + "\r\n" +
			_content_type + "\r\n" + "\r\n" + _buffString;
}

void Response::fDelete(Request &request, Server &serv)
{
	std::string filename = request.getPath();

	if (remove((filename).c_str()) == 0) // remove file
	{
		_response = status200;
		std::cout << NEW << "DELITED " << filename << END << std::endl;
		return;
	}
	//		std::string s = "<h1>File Delited!</h1>";
	_response = status404; // if remove is error
	error(serv);
}

int Response::check_path(Request request, bool cgi)
{
	std::ifstream file(request.getPath());

	if (file.is_open() == 0 && !cgi)
	{
		_response = status404;
		return (1);
	}
	read_buf(file);
	file.close();
	return (0);
}

void Response::defineContType(Request request)
{
	std::string extension;

	extension = request.getPath().substr(request.getPath().find_last_of(".") + 1);

	if (extension == "png")
		_content_type = "content-type: image/" + extension;
	else if (extension == "jpeg")
		_content_type = "content-type: image/jpeg";
	else if (extension == "jpg")
		_content_type = "content-type: image/jpg";
	else if (extension == "html" || extension == "css")
		_content_type = "content-type: text/" + extension;
	else if (extension == "ico")
		_content_type = "content-type: image/x-icon";
	else if (extension.find("cgi") > 0 && extension.find("cgi") != std::string::npos)
		_content_type = "content-type: application/x-www-form-urlencoded";
	else
		_content_type = "content-type: text";

//		std::cout << "extension " << extension << std::endl
//				  << std::endl;
//		std::cout << "conttype " << _content_type << std::endl
//		<< std::endl;
}
