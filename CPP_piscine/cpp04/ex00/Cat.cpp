#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
}

Cat & Cat::operator= (const Cat & other)
{
	this->_type = other.getType();
	return (*this);
}

Cat::Cat(const Cat & copy)
{
	std::cout << "Cat copy constructor" << std::endl;
	(*this) = copy;
}

void Cat::makeSound() const
{
	std::cout << "Meoooow" << std::endl;
}