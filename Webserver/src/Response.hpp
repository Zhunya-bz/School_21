#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include "Webserv.hpp"
#include "Request.hpp"
#include "CGI.hpp"

class Response
{
private:
	std::string _response;
	std::string _buffString;
	std::string _content_type; //= "content-type: image/jpeg\r\n";

	// open file and read in buff
	int check_path(Request request, bool cgi);
	void defineContType(Request request);
	int go_autoindex(Request &request);
	void change_path_autoindex(std::string & res, struct dirent *entry, std::string change);
	// go to error_page and open html file or redirect
	void error(Server &serv);
	int check_errors(Request request, Server &serv, bool cgi);
	void read_buf(std::ifstream &file);

	void CGIHandler(Request request, Server server, std::string cgiPath);
	std::string CGIHeaders(std::string response);
	std::string CGIDateHeader(void);
	std::string CGIStatus(std::string response);
	std::string ft_timestamp(time_t timestamp);
	std::string ft_getline(std::string source, size_t n);
	size_t ft_lines(std::string source);
	std::vector<std::string> ft_split(std::string str);


public:
	Response(){};
	~Response(){};

	Response(const Response &src);
	Response &operator=(const Response &rhs);

	std::string getBuffSting() const { return (_buffString); };
	std::string getContType() const { return (_content_type); };
	std::string getResp() const { return (_response); };

	void prepareResp(Request request, Server &serv);

	void fGet(Request &request);

	int fPost(Request & request, Server & serv);

	void fDelete(Request &request, Server &serv);

	void fUnknown(){};

};

#endif
