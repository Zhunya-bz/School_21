#include "Webserv.hpp"
#include "ServSockets.hpp"
#include "ListeningSocket.hpp"
#include "Config_parser/ParseConf.hpp"
#include "Container.hpp"

int msg_err(std::string msg)
{
	std::cerr << msg << std::endl;
	return (1);
}

int main(int argc, char **argv)
{
	signal(SIGPIPE, SIG_IGN);
	std::cout << RED << "\n\n-----START-----\033[0m" << std::endl
			  << std::endl
			  << std::endl;

	ParseConf pars;
	ServSockets servSockets;
	std::vector<Container> containers;
	std::vector<listeningSocket> listSockets;

	if (pars.readConf(pars, argc, argv))
		return (1);
	pars.create_listSock(listSockets);

	for (std::vector<listeningSocket>::iterator it = listSockets.begin(); it != listSockets.end(); )
	{
		if (it->createSocket() < 0) //ip adr get
		{
			it = listSockets.erase(it);
			continue;
		}
		it++;
		// change it later, if -1 remove socket from array, change socket number
	}
	if (listSockets.size() == 0)
	{
		std::cout << "No ports created!" <<std::endl;
		exit(1);
	}
//	int test = 0;
	while (true)
	{
//		std::cout << "\n\n********* ITERATION " << test << "*********\n\n";
		servSockets.emptyReadWriteFds();

		servSockets.addToRead(listSockets);
		servSockets.setSockets(containers);
		servSockets.checkSelect(listSockets, containers);
		servSockets.acceptNewSocket(listSockets, containers);
		servSockets.readRequest(containers);

		servSockets.sendResponse(containers);

		//check container
		// for (std::vector<Container>::iterator i = containers.begin(); i != containers.end(); i++)
		// {
		// 	std::cout << i->fd << " path = " << i->request.getPath() << std::endl;
		// }

//		test++;
	}

	return (0);
}
