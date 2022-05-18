#ifndef SOCKETS_HPP
#define SOCKETS_HPP

#include "Webserv.hpp"
#include "ListeningSocket.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "Container.hpp"

class ServSockets
{
private:
	fd_set	rfd;
	fd_set	wfd;
	int		newSocket;

public:
	ServSockets(){};
	~ServSockets(){};

	ServSockets(const ServSockets &copy);
	ServSockets &operator=(const ServSockets &rhs);

	void	emptyReadWriteFds();

	void	addToRead(std::vector<listeningSocket> &listSocket);

	void	setSockets(std::vector<Container> &containers);

	void	checkSelect(std::vector<listeningSocket> &listSocket, std::vector<Container> &containers);

	void	acceptNewSocket(std::vector<listeningSocket> &listSocket, std::vector<Container> &containers);

	void	decodeChunks(std::string strBuff);

	int		requestRecv(Container &pContainer);

	void	readRequest(std::vector<Container> &containers);

	void	sendResponse(std::vector<Container> &containers);

};

#endif