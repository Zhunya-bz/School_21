#include "Animal.hpp"

Animal::Animal() : _type("")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal & copy) : _type(copy._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
	(*this) = copy;
}

Animal & Animal::operator= (const Animal & other)
{
	this->_type = other.getType();
	return (*this);
}

std::string Animal::getType() const
{
	return (this->_type);
}

std::ostream& operator<< (std::ostream &out, const Animal &animal)
{
	out << animal.getType();
	return (out);
}

// такое можно, можно из дочерних вызывать этот метод
// void Cat::makeSound() const
//{ Animal::makeSound(); }
void Animal::makeSound() const
{
	std::cout << "Animal" << std::endl;
}