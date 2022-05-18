#ifndef LISTENINGSOCKET_HPP
#define LISTENINGSOCKET_HPP

#include "Webserv.hpp"

class listeningSocket
{
private:
	int					_fdNum;
//	sockaddr_in listeningSocketAddr;
//	int _status;
//	int portNum;
	int					_serv_port;
	std::string			_ip;
	std::vector<Server>	_servers; // тут лежат все серверы с одним ip и port

public:
	listeningSocket(){};
	~listeningSocket(){};

	listeningSocket(const listeningSocket &src);
	listeningSocket &operator=(const listeningSocket &rhs);

	int					getFd() const { return (_fdNum);}
	std::string			getIp() const {return (_ip);}
	int					getPort() const { return (_serv_port);}
	std::vector<Server> getServer() const {return _servers;}

	void				setPort(int serv_port) {_serv_port = serv_port;}
	void				setIp(std::string ip) {_ip = ip;}
	void				setServer(Server &serv) {_servers.push_back(serv);}

	int					createSocket();
};

#endif