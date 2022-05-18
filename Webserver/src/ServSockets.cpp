#include "ServSockets.hpp"

ServSockets::ServSockets(const ServSockets &copy)
{
	*this = copy;
}

ServSockets &ServSockets::operator=(const ServSockets &rhs)
{
	if (this != &rhs)
	{
		rfd = rhs.rfd;
		wfd = rhs.wfd;
		newSocket = rhs.newSocket;
	}
	return (*this);
}

void ServSockets::emptyReadWriteFds()
{
	FD_ZERO(&rfd);
	FD_ZERO(&wfd);
}

void ServSockets::addToRead(std::vector<listeningSocket> &listSocket)
{
	std::vector<listeningSocket>::iterator it = listSocket.begin();
	for (; it != listSocket.end(); it++)
		FD_SET(it->getFd(), &rfd);
}

void ServSockets::setSockets(std::vector<Container> &containers)
{
//	std::cout << std::endl;
	for (std::vector<Container>::iterator Iter = containers.begin(); Iter != containers.end(); Iter++)
	{
		if (Iter->getReadFd() == 1)
		{
			FD_SET(Iter->getFd(), &rfd);
//				std::cout << "fd " << Iter->fd << " is added to read " << std::endl;
		}
		if (Iter->getWriteFd() == 1)
		{
			FD_SET(Iter->getFd(), &wfd);
//				std::cout << "fd " << Iter->fd << " is added to write " << std::endl;
		}
	}
}

void ServSockets::checkSelect(std::vector<listeningSocket> &listSocket, std::vector<Container> &containers)
{
	int maxValue = listSocket[0].getFd();
	std::vector<listeningSocket>::iterator it = listSocket.begin();
	for (; it != listSocket.end(); it++)
	{
		if (maxValue < it->getFd())
			maxValue = it->getFd();
	}
	for (std::vector<Container>::iterator Iter = containers.begin(); Iter != containers.end(); Iter++)
	{
		if (maxValue < Iter->getFd())
			maxValue = Iter->getFd();
	}

	// std::cout<<"size of fd set = "<<sizeof(rfd) <<std::endl;
	// struct timeval wait_time;
	// wait_time.tv_sec = 5;
	// wait_time.tv_usec = 0;
	int res = select(maxValue + 1, &rfd, &wfd, NULL, NULL); // ? check later, probably add time for long requests
	if (res <= 0)
	{
		if (res == -1 && errno == EINTR)
			std::cerr << "select: process accepted a signal" << std::endl;
		else if (res == -1)
			std::cerr << "select: fd in set probably was closed" << std::endl;
		else if (res == 0)
			std::cerr << "select: time out!" << std::endl;
		return; //check later logic
	}
//		std::cout << "select result = " << res << std::endl;
}

void ServSockets::acceptNewSocket(std::vector<listeningSocket> &listSocket, std::vector<Container> &containers)
{
	std::vector<listeningSocket>::iterator it = listSocket.begin();
	for (; it != listSocket.end(); it++)
	{
		if (FD_ISSET(it->getFd(), &rfd))
		{
			newSocket = accept(it->getFd(), NULL, NULL);
			if (newSocket < 0)
				return;
			fcntl(newSocket, F_SETFL, O_NONBLOCK);
			Container container(newSocket, *it); // передаем первый сервер
			containers.push_back(container);
		}
	}
}

void ServSockets::decodeChunks(std::string strBuff)
{
	std::string::size_type p1;
	std::string::size_type p2;
	std::string::size_type headerLen = strBuff.find("\r\n\r\n");
	std::string header = strBuff.substr(0, headerLen + 4);
	std::string body = strBuff.substr(headerLen + 4);

	char *pEnd;
	size_t size = std::strtol(body.c_str(), &pEnd, 16);
	p1 = 0;
	while (size != 0)
	{
		p2 = body.find("\r\n", p1 + 1);
		body.erase(p1, p2 - p1 + 2);
		p1 = body.find("\r\n");
		size = std::strtol(body.c_str() + p1, &pEnd, 16);
		if (size == 0)
			body.erase(p1);
	}

	strBuff = header + body;
}

int ServSockets::requestRecv(Container &pContainer)
{
	int sizeRecv = 0;
	char buffer[BUFFER_SIZE];
	std::string s;
	sizeRecv = recv(pContainer.getFd(), buffer, BUFFER_SIZE - 1, 0);

	if (sizeRecv < 0 || sizeRecv == 0)
	{
		if (sizeRecv < 0)
			std::cerr << "error recv\n";
		if (sizeRecv == 0)
			std::cerr << "connection closed \n";
		return (-1);
	}
	buffer[sizeRecv] = '\0';
	s += buffer;
	pContainer.setStrBuf(pContainer.getStrBuff().append(buffer));
	//		std::cout << pContainer.
	//		std::cout << "CH STAT:" << pContainer.chunkStatus << std::endl;
	if (pContainer.getChunkStatus() == 0 && pContainer.getStrBuff().find("\r\n\r\n") != std::string::npos)
	{
		std::string::size_type pos1 = s.find("Transfer-Encoding:");
		std::string::size_type pos2 = s.find("chunked");
		if (pos1 != std::string::npos && pos2 != std::string::npos)
		{
			std::string transferEncRow = s.substr(pos1, pos2 - pos1);
			std::string::size_type posCRLF = transferEncRow.find("\r\n");
			if (posCRLF == std::string::npos)
				pContainer.setChunkStatus(chunk);
		}
		else
			pContainer.setChunkStatus(notChunk) ;
	}
	if (pContainer.getChunkStatus() == chunk && s.find("\0\r\n\r\n") != std::string::npos)
		return (1);
	else if (pContainer.getChunkStatus() == notChunk)
	{
		if (sizeRecv < BUFFER_SIZE - 1)
			return (1);
		std::string::size_type pos = pContainer.getStrBuff().find("Content-Length: ");
		unsigned long contLen = atoi(pContainer.getStrBuff().c_str() + pos + 16);
//		std::cout << "contLen = " << contLen << std::endl;
		int headerLen = (pContainer.getStrBuff().find("\r\n\r\n") + 4);
		if (pContainer.getStrBuff().length() - headerLen < contLen)
			return (0);
		else
			return (1);
	}

	return (0);
}

void ServSockets::readRequest(std::vector<Container> &containers)
{
	for (std::vector<Container>::iterator Iter = containers.begin(); Iter != containers.end();)
	{
//			std::cout << "!!iteration inside of read loop " << i++ << " fd = " << Iter->fd << std::endl;
		if (FD_ISSET(Iter->getFd(), &rfd))
		{
//				std::cout << "ready to read from fd " << Iter->fd << std::endl;
			int status = requestRecv(*Iter);
//			std::cout << "STATUS READ:" << status << std::endl;
			if (status == -1)
			{

				shutdown(Iter->getFd(), SHUT_RDWR);
				close(Iter->getFd());
				Iter = containers.erase(Iter);
				continue;
			}
			if (status == 1)
			{
				std::cout << "------------------------------------------------------------------------------" << std::endl;
				if (Iter->getChunkStatus() == chunk)
					decodeChunks(Iter->getStrBuff());
				std::cout << Iter->getStrBuff() << std::endl;
				std::cout << "------------------------------------------------------------------------------" << std::endl;
				Iter->parseRequest();
				Iter->prepareResp();

				Iter->setReadFd(0);
				Iter->setWriteFd(1);
				shutdown(Iter->getFd(), SHUT_RD);
			}
		}
		Iter++;
	}
}

void ServSockets::sendResponse(std::vector<Container> &containers)
{
//	int i = 0;
	for (std::vector<Container>::iterator Iter = containers.begin(); Iter != containers.end();)
	{
//			std::cout << "iteration inside of write loop: " << i++ << std::endl;

		if (FD_ISSET(Iter->getFd(), &wfd))
		{
//			std::cout << "fd " << Iter->getFd() << " is writting" << std::endl;
//				std::cout << Iter->request.getPath() << std::endl;
			Iter->sendResp();
//			std::cout << "size reamain = " << Iter->getSizeRemain() << std::endl;

			if (Iter->getSizeRemain() == 0)
			{
				Iter->setWriteFd(0);
//				std::cout << GREEN << Iter->getRequest().getPath() << "  was sent to fd " << Iter->getFd() << END <<
//						  std::endl;
				// for (int i = 0; i < 200; i++)
				// 	std::cout << Iter->response.getResult()[i];
//				std::cout << "\n";
				Iter->setWriteFd(0);
				shutdown(Iter->getFd(), SHUT_RDWR);
				close(Iter->getFd());
//					std::cout << Iter->fd << " removed" << std::endl;
				Iter = containers.erase(Iter);
				// std::cout << Iter->fd << " is next iter" << std::endl;
				continue;
			}
		}
		Iter++;
	}
}
