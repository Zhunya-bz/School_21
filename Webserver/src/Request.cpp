#include "Request.hpp"

Request::Request(const Request &src)
{
	*this = src;
	return;
}

Request &Request::operator=(const Request &rhs)
{
	if (this != &rhs)
	{
		_method = rhs._method;
		_path = rhs._path;
		_version = rhs._version;
		_host = rhs._host;
		_chunked = rhs._chunked;
		_contentType = rhs._contentType;
		_contentLen = rhs._contentLen;
		_body = rhs._body;
		_type = rhs._type;
//			_headerMap = rhs._headerMap;
		_local = rhs._local;
		_reqPath = rhs._reqPath;
	}
	return *this;
}

std::string Request::set_headers(std::string name_head, std::string str)
{
	size_t count_find = str.find(name_head);
	if (count_find != std::string::npos)
	{
		std::string res = str.substr(count_find + name_head.length() + 1, str.find("\r\n",
				str.find(name_head)) - (count_find +name_head.length()));
		return (res);
	}
	return ("");
}

void Request::set_server_by_name( listeningSocket & listSock, Server & serv)
{
	// выбираем какой сервер нужно будет применить из конфиг файла
	std::vector<Server> s = listSock.getServer();
	serv = *(s.begin()); // если не нашли берем первый

	for (std::vector<Server>::iterator it = s.begin(); it != s.end(); it++)
	{
		for (std::vector<std::string>::iterator itstr = it->getServerName().begin(); itstr != it->getServerName()
				.end(); itstr++)
		{
			if (_host == *itstr)
			{
				serv = *it;
				break;
			}
		}
	}
}

void Request::set_location(Server & serv)
{
	int fl = -1;

	for (size_t i = 0; i < serv.getLocation().size(); i++)
	{
		if (serv.getLocation()[i].getIsGeneral() == true)
		{
			fl = i;
			continue;
		}
		// c - количество символов в config file in path
		int c = serv.getLocation()[i].getPath().size();
		if (c == 1)
			continue;
		// _path - from GET request
		size_t num = _path.find(serv.getLocation()[i].getPath().c_str(), 0, c);
		//			std::cout <<"NUM:" << num << std::endl;
		if (num != std::string::npos)
		{
			std::string str;
			str = serv.getLocation()[i].getRoot();
			str += _path.erase(num, c);
			_path = str;
			_local = serv.getLocation()[i];
			fl = -1;
			break;
		}
	}
	if (fl >= 0)
	{
		if (serv.getLocation()[fl].getIsGeneral() == true && _path == "/")
		{
			_path = serv.getLocation()[fl].getRoot();
			_local = serv.getLocation()[fl];
			if (!_local.getIndex().empty())
				_path += _local.getIndex();
		}
		else
		{
			std::string str;
			str = serv.getLocation()[fl].getRoot();
			str += _path;
			_path = str;
			_local = serv.getLocation()[fl];
		}
	}
}


void Request::parseRequest(std::string str, listeningSocket & listSock, Server & serv)
{
	std::string firstStr;
	size_t len;
	size_t pos;

	len = str.find("\r\n");
	firstStr = str.substr(0, len);
	pos = firstStr.find(" ");
	setMethod(firstStr.substr(0, pos));
	setPath(firstStr.substr(pos + 1, firstStr.find(" ", pos + 1) - pos - 1));
	setVersion(firstStr.substr(firstStr.find(" ", pos + 1) + 1));
	_reqPath = _path;

	setHost(set_headers("Host:", str));
	setType(set_headers("Sec-Fetch-Dest:", str));
	std::string conlen = set_headers("Content-Length:", str);
	if (!conlen.empty())
		setContentLen(std::stoi(conlen));
	setContentType(set_headers("Content-Type:", str));

	if (str.find("chunked") != std::string::npos)
		setChunked(true);

	size_t findEmptyStr = str.find("\r\n\r\n");

	setBody(str.substr(findEmptyStr + 4));

	set_server_by_name(listSock, serv);

	set_location(serv);


//	std::cout << YELOW << "PATH = " << _path << std::endl;
//	std::cout << "METHOD = " << _method << std::endl;
//	std::cout << "SERV NAME[0] = " << serv.getServerName()[0] << std::endl;
//	std::cout << "LOCATION = " << _local.getPath() << END << std::endl;

}