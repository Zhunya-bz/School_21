#include "PhoneBook.hpp"

int main()
{
	std::string command;
	PhoneBook book;

	do
	{
		std::cout << "Enter the command (EXIT, ADD, SEARCH):" << std::endl;
		if (!(std::getline(std::cin, command)))  //ctrl+d
			break;
		if (!command.compare("ADD"))
			book.add();
		else if (!command.compare("EXIT"))
			break ;
		else if (!command.compare("SEARCH"))
			book.search();
		else
			continue;
	} while (command.compare("EXIT")); // пока не ввели exit идем
	return (0);
}