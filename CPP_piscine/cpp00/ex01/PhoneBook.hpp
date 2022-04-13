#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
#include <stdlib.h>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact		book[8];
	int			count;

	int			read_str(std::string enter, int flag, Contact person[8], int i);
	std::string	number_list(int i);

public:
	PhoneBook();
	~PhoneBook();
	void		set_value(Contact value, int i);
	void		set_count(int value);
	std::string get_book_first_name(int i);
	std::string get_book_last_name(int i);
	std::string get_book_nickname(int i);
	std::string get_book_phone_number(int i);
	std::string get_book_secret(int i);

	void		add();
	void		search();
};

#endif //CPP01_PHONEBOOK_HPP
