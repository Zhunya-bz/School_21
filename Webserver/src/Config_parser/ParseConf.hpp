#ifndef WEBSERV_PARSECONF_HPP
#define WEBSERV_PARSECONF_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include <cstring>
#include "Server.hpp"
#include "../ListeningSocket.hpp"

class listeningSocket;

class ParseConf
{
private:
	void set_server_header(std::string key, std::vector<std::string> value, Server &ser);
	void set_location_header(std::string key, std::vector<std::string> value, Location &loc);
	std::vector<std::string> get_value(std::string str, int &i, std::vector<std::string> value);
	std::string get_key(std::string str, int &i);
	void set_location(std::string key, std::vector<std::string> value, std::ifstream &file, std::string str,
					  std::vector<Location> &all_loc);

	std::vector<Server> _all_ser;

public:
	ParseConf(){};
	~ParseConf(){};

	void set_allSer(std::vector<Server> allSer) {allSer = _all_ser;};
	std::vector<Server> getAllSer() const {return (_all_ser);};
	void create_listSock(std::vector<listeningSocket> &listSockets);

	int readConf(ParseConf &pars, int argc, char **argv);

	void	parser(std::string conf);

	struct MyException : public std::exception
	{
	private:
		const char *errorMsg;

	public:
		MyException (const char* str){
			errorMsg = str;
		}
		const char * what () const throw ()
		{
			return errorMsg;
		}
	};
};


#endif //WEBSERV_PARSECONF_HPP
