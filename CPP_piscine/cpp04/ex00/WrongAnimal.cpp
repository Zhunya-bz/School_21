#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	(*this) = copy;
}

WrongAnimal & WrongAnimal::operator= (const WrongAnimal & other)
{
	this->_type = other.getType();
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

std::ostream& operator<< (std::ostream &out, const WrongAnimal &animal)
{
	out << animal.getType();
	return (out);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Krya-Krya" << std::endl;
}