#ifndef WEB_MERGE_REQUEST_HPP
#define WEB_MERGE_REQUEST_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

#include "Webserv.hpp"
#include "ListeningSocket.hpp"
// #include "Request.hpp"

class Request
{
private:
	std::string _method;
	std::string _path;
	std::string _reqPath;
	std::string _version;
	std::string _host; // server name
	bool 		_chunked;
	std::string _contentType;
	int 		_contentLen;
//	std::map<std::string, std::string> _headerMap;
	std::string _body;
	std::string _type;
	Location	_local;

	std::string set_headers(std::string name_head, std::string str);
	void set_server_by_name( listeningSocket & listSock, Server & serv);
	void set_location(Server & serv);

public:
	Request() : _method("Unknown"), _chunked(false), _contentLen(0){};
	~Request() {};

	Request(const Request &src);
	Request &operator=(const Request &rhs);

	void setMethod(std::string method) { _method = method; }
	void setPath(std::string path) { _path = path; }
	void setVersion(std::string version) { _version = version; }
	void setHost(std::string host) { _host = host; }
	void setChunked(bool chunked) { _chunked = chunked; }
	void setContentType(std::string contentType) { _contentType = contentType; }
	void setContentLen(int contentLen) { _contentLen = contentLen; }
//	void setHeaderMap(std::map<std::string, std::string> headerMap) { _headerMap = headerMap; }
	void setBody(std::string body) { _body = body; }
	void setType(std::string type) { _type = type; }
	void setLocation(Location local) { _local = local; }
	void setReqPath(std::string reqPath) { _reqPath = reqPath; }

	std::string getMethod() const { return (_method); }
	std::string getPath() const { return (_path); }
	std::string getVersion() const { return (_version); }
	std::string getHost() const { return (_host); }
	bool getChunked() const { return (_chunked); }
	std::string getContentType() const { return (_contentType); }
	int getContentLen() const { return (_contentLen); }
//	std::map<std::string, std::string> getHeaderMap() const { return (_headerMap); }
	std::string getBody() const { return (_body); }
	std::string getType() const { return (_type); }
	Location getLocationReq() const { return (_local); }
	std::string getReqPath() const { return (_reqPath); }

	void parseRequest(std::string str, listeningSocket & listSock, Server & serv);

};

#endif //WEB_MERGE_REQUEST_HPP
