#include "ListeningSocket.hpp"

listeningSocket::listeningSocket(const listeningSocket &src)
{
	*this = src;
}

listeningSocket &listeningSocket::operator=(const listeningSocket &rhs)
{
	if (this != &rhs)
	{
		_fdNum = rhs._fdNum;
//			_status = rhs._status;
		_ip = rhs._ip;
		_serv_port = rhs._serv_port;
		_servers = rhs._servers;

	}
	return *this;
}

int listeningSocket::createSocket()
{
	//		portNum = serverPort;
	_fdNum = socket(AF_INET, SOCK_STREAM, 0);
	fcntl(_fdNum, F_SETFL, O_NONBLOCK);
	sockaddr_in listeningSocketAddr;

	listeningSocketAddr.sin_family = AF_INET;
	listeningSocketAddr.sin_port = htons(_serv_port);			 // defferent byte orders to hosts and newtwork
	listeningSocketAddr.sin_addr.s_addr = inet_addr(_ip.c_str()); // check it later
	int opt = 1;
	setsockopt(_fdNum, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)); //for the case if prev server connection was
	// ended incorrectly. handle later returning -1
	if (bind(_fdNum, (sockaddr *)&listeningSocketAddr, sizeof(listeningSocketAddr)) == -1)
	{
		std::cerr << "bind error: " << strerror(errno) << std::endl;
//			status = -1;
		return (-1);
	}

	if (listen(_fdNum, SOMAXCONN) == -1) //SOMAXCONN len = 128, кол-во одновременно подключ соед, очередь
	{
		std::cerr << "listen error" << std::endl;
//			status = -1;
		return (-1);
	}
//		status = 0;
	return (0);
}

