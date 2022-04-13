#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
}

Dog & Dog::operator= (const Dog & other)
{
	this->_type = other.getType();
	return (*this);
}

Dog::Dog(const Dog & copy)
{
	std::cout << "Dog copy constructor" << std::endl;
	(*this) = copy;
}

void Dog::makeSound() const
{
	std::cout << "Gav-Gav" << std::endl;
}
