#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
//	std::cout << "Constructor called PhoneBook" << this  <<std::endl;
	this->count = 0;
}

PhoneBook::~PhoneBook()
{
//	std::cout << "Destructor called PhoneBook" << this << std::endl;
}

int PhoneBook::read_str(std::string enter, int flag, Contact person[8], int i)
{
	std::string str;

	std::cout << enter << std::endl;
	std::getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "Error"<< std::endl;
		return (1);
	}
	if (flag == 0)
		person[i].set_first_name(str);
	else if (flag == 1)
		person[i].set_last_name(str);
	else if (flag == 2)
		person[i].set_nickname(str);
	else if (flag == 3)
		person[i].set_phone_number(str);
	else if (flag == 4)
		person[i].set_secret(str);
	return (0);
}

void PhoneBook::add()
{
	while (read_str("Enter the first name", 0, this->book, this->count % 8))
		;
	while (read_str("Enter the last name", 1, this->book, this->count % 8))
		;
	while (read_str("Enter the nickname", 2, this->book, this->count % 8))
		;
	while (read_str("Enter the phone number", 3, this->book, this->count % 8))
		;
	while (read_str("Enter the darkest secret", 4, this->book, this->count % 8))
		;
	this->count++;
}

std::string PhoneBook::number_list(int i)
{
	std::string num;
	int fl;

	if (i == 0)
		return ("");
	do
	{
		fl = 0;
		std::cout << "Please enter the number of list" << std::endl;
		std::getline(std::cin, num);
		for (size_t k = 0; k < num.length(); ++k)
			if (!std::isdigit(num[k]))
			{
				std::cout<<"Error"<< std::endl;
				fl = 1;
				break;
			}
		if (fl != 1 && !num.empty() && (std::stoi(num) - 1 >= i || std::stoi(num) == 0))
		{
			std::cout<<"Error"<< std::endl;
			fl = 1;
		}
	} while (fl == 1);
	return (num);
}

void PhoneBook::search()
{
	int j = 0;
	std::string num;
	int k;

	std::cout << "\n|     index|first name| last name|  nickname|" << std::endl;
	if (this->count > 8)
		k = 8;
	else
		k = this->count;
	while (j < k)
	{
		std::cout << "|" << std::setw(10) << j + 1;
		if (this->get_book_first_name(j).length() > 10)
			std::cout << "|" << std::setw(9) << this->get_book_first_name(j).substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->get_book_first_name(j);
		if (this->get_book_last_name(j).length() > 10)
			std::cout << "|" << std::setw(9) << this->get_book_last_name(j).substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->get_book_last_name(j);
		if (this->get_book_nickname(j).length() > 10)
			std::cout << "|" << std::setw(9) << this->get_book_nickname(j).substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << this->get_book_nickname(j) << "|" << std::endl;
		++j;
	}
	std::cout << "\n";
	num = number_list(this->count);
	if (!num.empty())
	{
		std::cout << "\nfirst name: " <<get_book_first_name(std::stoi(num) - 1) << std::endl;
		std::cout << "last name: " << get_book_last_name(std::stoi(num) - 1) << std::endl;
		std::cout << "nickname: "<< get_book_nickname(std::stoi(num) - 1) << std::endl;
		std::cout << "phone number: "<< get_book_phone_number(std::stoi(num) - 1) << std::endl;
		std::cout << "darkest secret: "<< get_book_secret(std::stoi(num) - 1) << "\n"<< std::endl;
	}
}

void PhoneBook::set_value(Contact value, int i)
{
	this->book[i] = value;
}

void PhoneBook::set_count(int value)
{
	this->count = value;
}

std::string PhoneBook::get_book_first_name(int i)
{
	return (this->book[i].get_first_name());
}

std::string PhoneBook::get_book_last_name(int i)
{
	return (this->book[i].get_last_name());
}

std::string PhoneBook::get_book_nickname(int i)
{
	return (this->book[i].get_nickname());
}

std::string PhoneBook::get_book_phone_number(int i)
{
	return (this->book[i].get_phone_number());
}

std::string PhoneBook::get_book_secret(int i)
{
	return (this->book[i].get_secret());
}
