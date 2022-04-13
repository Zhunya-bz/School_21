#include "PhoneBook.hpp"

Contact::Contact()
{
//	std::cout << "Constructor called Contact" << this << std::endl;
}

Contact::~Contact()
{
//	std::cout << "Destructor called Contact" << this << std::endl;
}

std::string Contact::get_first_name()
{
	return (this->first_name);
}

std::string Contact::get_last_name()
{
	return (this->last_name);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

std::string Contact::get_phone_number()
{
	return (this->phone_number);
}

std::string Contact::get_secret()
{
	return (this->secret);
}

void Contact::set_first_name(std::string value)
{
	this->first_name = value;
}

void Contact::set_last_name(std::string value)
{
	this->last_name = value;
}

void Contact::set_nickname(std::string value)
{
	this->nickname = value;
}

void Contact::set_phone_number(std::string value)
{
	this->phone_number = value;
}

void Contact::set_secret(std::string value)
{
	this->secret = value;
}
