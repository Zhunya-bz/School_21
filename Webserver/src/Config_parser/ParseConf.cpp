 #include "ParseConf.hpp"

void ParseConf::set_server_header(std::string key, std::vector<std::string> value, Server &ser)
{
	if (key == "host" && ser.getIp().empty())
		ser.setIp(value[0]);
	else if (key == "port" && ser.getPort() == 0)
	{
		int port = std::stoi(value[0]);
		if (port < 1 || port >= 65536)
			throw MyException("Error port!");
		ser.setPort(port);
	}
	else if (key == "server_name" && ser.getServerName().empty())
		ser.setServerName(value);
	else if (key == "error_page" && ser.getErrorPage().empty())
	{
		ser.setErrorPage(value);
	}
	else if (key == "client_max_body_size" && ser.getMaxSize() == 0)
		ser.setMaxSize(std::stoi(value[0]));
		// ser.setMaxSize(1000000000);
	else
		throw MyException("Double name!");
}

void ParseConf::set_location_header(std::string key, std::vector<std::string> value, Location &loc)
{
	if (key == "root" && loc.getRoot().empty())
		loc.setRoot(value[0]);
	else if (key == "allowed_methods" && loc.getMethods().empty())
		loc.setMethods(value);
	else if (key == "index" && loc.getIndex().empty())
		loc.setIndex(value[0]);
	else if (key == "autoindex" && !loc.getAutoIndex())
	{
		if (value[0] == "on")
			loc.setAutoIndex(true);
	}
	else if (key == "upload_route" && loc.getUploadRoute().empty())
		loc.setUploadRoute(value[0]);
	else if (key == "redirect" && loc.getRedirect().empty())
		loc.setRedirect(value[0]);
	else if (key == "cgi_path" && loc.getCGI().empty())
		loc.setCGI(value[0]);
	else
		throw MyException("Wrong name!");
}

std::vector<std::string> ParseConf::get_value(std::string str, int &i, std::vector<std::string> value)
{
	int start = 0;

	while (str[i] != ';')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'))
			i++;
		start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\v' && str[i] != ';'))
			i++;
		if (i == start)
			break;
		value.push_back(str.substr(start, i - start));
		//		std::cout << "value = |" << value[0] << "|" << std::endl;
		//		if (value.size() == 2)
		//			std::cout << "value = |" << value[1] << "|" << std::endl;
	}
	return (value);
}

std::string ParseConf::get_key(std::string str, int &i)
{
	int start = 0;

	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'))
		i++;
	start = i;
	while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\v'))
		i++;
	//	std::cout << "key = " << str.substr(start, i - start) << std::endl; // comment
	return (str.substr(start, i - start));
}

void ParseConf::set_location(std::string key, std::vector<std::string> value, std::ifstream &file,
							 std::string str, std::vector<Location> &all_loc)
{
	Location loc;
	loc.setPath(value[0]);
	if (value[0] == "/")
		loc.setIsGeneral(true);

	while (std::getline(file, str) && str != "}")
	{
		int i = 0;
		if (str.empty())
			continue;
		key = get_key(str, i);
		if (key == "}")
			break;
		if (str[str.size() - 1] != ';') // проверяем на наличие ;
			throw MyException("Error syntax!");
		std::vector<std::string> value;
		value = get_value(str, i, value);
		set_location_header(key, value, loc);
	}
	all_loc.push_back(loc);
}

void ParseConf::parser(std::string conf)
{
	std::string str;		  // сюда будем класть считанные строки
	std::ifstream file(conf); // файл из которого читаем (для линукс путь будет выглядеть по другому)

	if (!file)
		throw MyException("Error opening file!");

	while (std::getline(file, str)) // цикл по поиску сервера
	{
		// читаем одну строку и сравниваем ее с сервером
		if (str.empty())
			continue;
		int i = 0;
		std::string key = get_key(str, i);
		std::vector<std::string> value;
		value = get_value(str, i, value);
		if (key == "server" && value.size() == 1 && value[0] == "{")
		{
			Server ser;
			std::vector<Location> all_loc;
			while (std::getline(file, str) && str != "}") // цикл внутри сервера
			{
				i = 0;
				if (str.empty())
					continue;
				key = get_key(str, i);
				if (key == "server" && value.size() == 1 && value[0] == "{")
					throw MyException("Error syntax!"); // если встречаем еще один сервер или не закрыли скобку

				std::vector<std::string> value;
				value = get_value(str, i, value);

				if (key == "location")
				{
					set_location(key, value, file, str, all_loc); // записываем переменные в класс Location
					continue;
				}
				if (str[str.size() - 1] != ';') // проверяем на наличие ;
					throw MyException("Error syntax!");

				set_server_header(key, value, ser); // записываем в наш сервер переменные
			}
			ser.setLocation(all_loc);
			_all_ser.push_back(ser);

		}
		else
			throw MyException("Wrong config file!");
	}
	//	std:: cout << BLUE <<all_ser[0].getMaxSize() << std::endl;
	//	std:: cout << BLUE <<all_ser[1].getMaxSize() << std::endl;
	//	std:: cout << BLUE <<all_ser[0].getServerName()[0]<< std::endl;
	//	std:: cout << BLUE <<all_ser[1].getServerName()[0] << std::endl;
	//	std:: cout << BLUE <<all_ser.size() << std::endl;

	file.close(); // обязательно закрываем файл что бы не повредить его
}

int ParseConf::readConf(ParseConf &pars, int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			pars.parser(argv[1]);
		}
		catch (std::exception &ex)
		{
			std::cout << ex.what() << std::endl;
			return (1);
		}
	}
	else if (argc == 1)
	{
		try
		{
			pars.parser("/Users/saltmer/Desktop/webserv/config/num1.conf");
		}
		catch (std::exception &ex)
		{
			std::cout << ex.what() << std::endl;
			return (1);
		}
	}
	else
	{
		std::cout << "Wrong Argument!" << std::endl;
		return (1);
	}
	return (0);
}

void ParseConf::create_listSock(std::vector<listeningSocket> &listSockets)
{
	for (std::vector<Server>::iterator it = _all_ser.begin(); it != _all_ser.end(); it++)
	{
		int fl = 0;
		if (listSockets.size() == 0)
			fl = 1;

		std::vector<listeningSocket>::iterator itL = listSockets.begin();
		for (; itL != listSockets.end(); itL++)
		{
			if (itL->getPort() == it->getPort() && itL->getIp() == it->getIp())
			{
				itL->setServer(*it);
				fl = 0;
				break;
			}
		}

		if ( itL == listSockets.end() && listSockets.size() != 0)
			fl = 1;

		if (fl == 1)
		{
			listeningSocket sock;
			sock.setPort(it->getPort());
			sock.setIp(it->getIp());
			sock.setServer(*it);
			listSockets.push_back(sock);
		}
	}
}
