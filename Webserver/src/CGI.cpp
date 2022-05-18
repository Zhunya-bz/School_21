#include "CGI.hpp"
#include <unistd.h>
#include <errno.h>

CGI::CGI(std::string cgi_path, std::string res_path, Request request, Server server, Location location)
: _cgi_path(cgi_path), _res_path(res_path), _request(request), _server(server), _location(location) {}

CGI::~CGI(void) {}

std::string CGI::getOutput(void) {
	std::map<std::string, std::string> args;
	char **args_converted;

	std::string res;
	args = getEnv();
	args_converted = convertEnv(args);

//	int i = -1;
//	while (args_converted[++i])
//		 std::cout << YELOW << args_converted[i] << END << std::endl;

	try { res = execCGI(args_converted); }
	catch (std::exception & e) { throw new CGIException(); }
	return (res);
}

std::string ft_replace(std::string source, std::string to_replace, std::string new_value) {
	size_t start_pos = 0;

	while((start_pos = source.find(to_replace, start_pos)) != std::string::npos) {
		source.replace(start_pos, to_replace.length(), new_value);
		start_pos += new_value.length();
	}
	return (source);
}

std::string CGI::readFile(std::string file) {
	char buffer[BUFFER_SIZE + 1] = {0};
	int fd;
	int i;
	int res;
	std::string result;

	fd = open(file.c_str(), O_RDONLY);
	if (fd < -1)
	{
		std::cout << "Error" << std::endl;
		throw new CGIException("The file " + file + " does not exists.");
	}
	while ((res = read(fd, buffer, BUFFER_SIZE)) > 0) {
		result += buffer;
		i = 0;
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
	}
	if (res < 0)
		throw new CGIException("Error while reading " + file + ".");
	close(fd);
	return (result);
}

std::string CGI::getUri(std::string somePath) {
	int pos = 0;
	std::string ret;

	ret = somePath;
	// std::cout << "somePath: " << somePath << std::endl;
	if ((pos = ret.find('?')) > 0) {
		// std::cout << "pos: " << pos << std::endl;
		ret = ret.substr(0, pos);
	}
	// std::cout << "ret: " << ret << std::endl;
	pos = ret.find_last_of("/\\");
	// std::cout << "pos: " << pos << std::endl;

	ret = ret.substr(pos);
	ret = ret.c_str();
	return ret;
}

std::string CGI::getQueryString(void) {
	int i = 0;

	while (_request.getPath()[i] && _request.getPath()[i] != '?') {	i++; }
	if (_request.getPath()[i] == '?') { i++; }
	return (std::string(_request.getPath(), i, -i));
}

std::string CGI::removeQueryArgs(std::string query) {
	int i = 0;

	while (query[i] && query[i] != '?') { i++; }
	return (std::string(query, 0, i));
}

std::map<std::string, std::string> CGI::getEnv(void) {
	std::map<std::string, std::string> args;
	std::map<std::string, std::string>::iterator it;
	std::string tmp;

	char *cwd = getcwd(NULL, 0);
	_cwd = cwd;
	free(cwd);

	// std::cout << "_cwd: " << _cwd << std::endl;

	args["CONTENT_LENGTH"] = std::to_string(_request.getContentLen());
	args["CONTENT_TYPE"] = _request.getContentType();
	args["GATEWAY_INTERFACE"] = "CGI/1.1";
	args["PATH_INFO"] = getUri(_cgi_path);
	args["PATH_TRANSLATED"] = removeQueryArgs(ft_replace(_cgi_path, "//", "/"));

	args["QUERY_STRING"] = getQueryString();
	args["REDIRECT_STATUS"] = std::to_string(200);
	args["REQUEST_METHOD"] = _request.getMethod();
	args["REQUEST_URI"] = getUri(_cgi_path);

	args["REMOTE_ADDR"] = _server.getIp();
	args["REMOTE_IDENT"] = "";

	args["SERVER_NAME"] = _server.getServerName()[0];
	args["SERVER_PORT"] = std::to_string(_server.getPort());
	args["SERVER_PROTOCOL"] = "HTTP/1.1";
	args["SERVER_SOFTWARE"] = "webserv/1.0";
	args["SCRIPT_FILENAME"] = removeQueryArgs(ft_replace(_cgi_path, "//", "/"));
	args["SCRIPT_NAME"] = getUri(_cgi_path);
	return args;
}

char *CGI::newStr(std::string src) {
	char *res;

	if (!(res = (char *)malloc(sizeof(char) * (src.size() + 1))))
		return 0;
	for (size_t i = 0; i < src.size(); ++i)
		res[i] = src[i];
	res[src.size()] = 0;
	return res;
}

std::string CGI::getScriptName(void) {
	int i = 0;

	while (_request.getPath()[i] && _request.getPath()[i] != '?') { ++i; }
	return (std::string(_request.getPath(), 0, i));
}

char **CGI::convertEnv(std::map<std::string, std::string> args) {
	char **result;
	std::map<std::string, std::string>::iterator it;
	int i;

	if (!(result = (char **)malloc(sizeof(char *) * (args.size() + 1))))
		return 0;
	i = 0;
	for (it = args.begin(); it != args.end(); it++)
		result[i++] = newStr(it->first + "=" + it->second);
	result[args.size()] = 0;
	return (result);
}

void CGI::freeArgs(char **args) {
	int i = 0;

	while (args[i]) { free(args[i++]); }
	free(args);
}

char **CGI::getExecArgs(void) {
	char **args;

	if (!(args = (char **)malloc(sizeof(char *) * 3)))
		return (0);
	args[0] = newStr(_cgi_path);
	args[1] = newStr(_res_path);
	args[2] = 0;
	return (args);
}

std::string CGI::execCGI(char **args) {
	pid_t pid;
	int exec_res;
	char **exec_args;
	int tmp_fd;
	int fd[2];

	exec_args = getExecArgs();
	// std::cout << "exec_args: "<< std::endl;
	// while (exec_args[++i])
	// 	std::cout << exec_args[i] << std::endl;

	if (pipe(fd) == -1)
		throw CGIException("Cannot create pipe to execute CGI.");
	pid = fork();
	if (pid == 0) {
		close(fd[1]);
		dup2(fd[0], 0);
		tmp_fd = open("/tmp/webserv_cgi", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (tmp_fd < 0)
			throw CGIException("Cannot create temporary file to catch CGI output in /tmp.");
		dup2(tmp_fd, 1);
		dup2(tmp_fd, 2);
		exec_res = execve(_cgi_path.c_str(), exec_args, args);
		// std::cout << "exec_res: " << exec_res << std::endl;
		// std::cout << "errno: " << errno << std::endl;

		close(0);
		close(tmp_fd);
		close(fd[0]);
		exit(0);
	} else {
		close(fd[0]);
		write(fd[1], _request.getBody().c_str(), _request.getBody().length());
		close(fd[1]);
		waitpid(-1, NULL, 0);
		freeArgs(args);
		freeArgs(exec_args);
	}
	return (readFile("/tmp/webserv_cgi"));
}


