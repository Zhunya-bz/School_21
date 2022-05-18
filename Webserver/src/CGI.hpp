#pragma once

#ifndef CGI_HPP
# define CGI_HPP

# include <iostream>
# include <string>
# include <map>
# include "Config_parser/Location.hpp"
# include "Config_parser/Server.hpp"
# include "Request.hpp"

class CGI
{
	private:
		std::string	_cwd;
		std::string _cgi_path;
		std::string _res_path;
		Request _request;
		Server _server;
		Location _location;

		std::map<std::string, std::string> getEnv(void);
		std::string getQueryString(void);
		std::string removeQueryArgs(std::string query);
		std::string getScriptName(void);
		std::string getUri(std::string somePath);

		char *newStr(std::string source);
		char **convertEnv(std::map<std::string, std::string> args);
		char **getExecArgs(void);
		void freeArgs(char **args);
		std::string execCGI(char **args);
		std::string readFile(std::string file);

	public:
		CGI(void);
		CGI(std::string cgi_path, std::string _res_path, Request request, Server server, Location location);
		~CGI(void);
		std::string getOutput(void);

};

class CGIException : public std::exception
{
	private:
		std::string _msg;
	public:
		CGIException(std::string message = "Unable to execute CGI.")
		: _msg(message) {};
		~CGIException() throw() {};
		const char *what () const throw () { return (_msg.c_str()); };
};

#endif
