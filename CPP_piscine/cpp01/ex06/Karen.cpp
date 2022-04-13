#include "Karen.hpp"

Karen::Karen()
{
	arr[0] = &Karen::debug;
	arr[1] = &Karen::info;
	arr[2] = &Karen::warning;
	arr[3] = &Karen::error;
}

Karen::~Karen()
{

}

void Karen::debug()
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI just "
				 "love it!" << std::endl;
}

void Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough!\nIf you did I would not "
				 "have to ask for it!" << std::endl;
}

void Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just"
				 " started working here last month." << std::endl;
}

void Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
	int i = 0;
	std::string all_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for ( ; i < 4; i++)
	{
		if (!all_level[i].compare(level))
			break;
	}
	switch (i)
	{
		case 0:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			(this->*(arr[0]))();
			std::cout << "\n";
		}
		case 1:
		{
			std::cout << "[ INFO ]" << std::endl;
			(this->*(arr[1]))();
			std::cout << "\n";
		}
		case 2:
		{
			std::cout << "[ WARNING ]" << std::endl;
			(this->*(arr[2]))();
			std::cout << "\n";
		}
		case 3:
		{
			std::cout << "[ ERROR ]" << std::endl;
			(this->*(arr[3]))();
			break;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

}