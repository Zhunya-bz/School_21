#ifndef WEBSERV_SERVER_HPP
#define WEBSERV_SERVER_HPP

#include "Location.hpp"

class Server
{
private:
	std::string					_ip;
	int 						_port;
	std::vector<std::string>	_server_name;
	std::map<int, std::string>	_error_page;
	int 						_max_body_size;
	std::vector<Location>		_location;

public:
	Server():_ip(""), _port(0), _max_body_size(0){};
	~Server(){};

	Server(const Server &src)
	{
		*this = src;
		return;
	};
	Server &operator= (const Server &rhs)
	{
		if (this != &rhs)
		{
			_ip = rhs._ip;
			_port = rhs._port;
			_server_name = rhs._server_name;
			_error_page = rhs._error_page;
			_max_body_size = rhs._max_body_size;
			_location = rhs._location;
		}
		return *this;
	};

	void setIp(std::string ip) {_ip = ip;};
	void setPort(int port) {_port = port;};
	void setServerName(std::vector<std::string>	server_name) {_server_name = server_name;};
	void setErrorPage(std::vector<std::string> error_page)
	{_error_page.insert(std::make_pair(std::stoi(error_page[0]), error_page[1]));};
	void setMaxSize(int max_size) {_max_body_size = max_size;};
	void setLocation(std::vector<Location>		location) {_location = location;};

	std::string getIp() const {return (_ip);};
	int getPort() const {return (_port);};
	std::vector<std::string> getServerName() const {return (_server_name);};
	std::map<int, std::string> getErrorPage() const {return (_error_page);}
	int getMaxSize() const {return (_max_body_size);};
	std::vector<Location> getLocation() const {return (_location);};
};


#endif //WEBSERV_PASRECONF_HPP
