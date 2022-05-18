#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <cerrno>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <csignal>
#include <cstdlib>
#include <cstdio>

#include <sys/socket.h>
#include <arpa/inet.h>

#include <unistd.h>

#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>

// #include "Request.hpp"
// #include "Response.hpp"

#include "Config_parser/ParseConf.hpp"

// #define CHUNK_SIZE 10000
#define BUFFER_SIZE 20000
// #define WEB_PRINT_HEADER() std::cout<<

#define GREEN "\033[0;32m"
#define YELOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NEW "\033[0;35m"
#define END "\033[0m"
#define RED "\033[0;31m"

#define status200 "HTTP/1.1 200 OK\r\n"
#define status404 "HTTP/1.1 404 Not Found\r\n"
#define status405 "HTTP/1.1 405 Method Not Allowed\r\n"

#define saltmer lelle

typedef enum
{
	chunk = 1,
	notChunk = 2
} chunkStatusEnum;

typedef enum
{
	httpUnknown = 0,
	httpGet,
	httpPost,
	httpDelete

} httpMethods;

int msg_err(std::string msg);
// std::string parseRequest(std::string str, Request &request);
//int readConf(ParseConf &pars, int argc, char **argv, std::vector<listeningSocket> &listSockets);

#endif