#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	Dogptr = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
	delete Dogptr;
}

Dog::Dog(const Dog & copy)
{
	std::cout << "Dog copy constructor" << std::endl;
	Dogptr = new Brain();
	(*this) = copy;
}

Dog & Dog::operator= (const Dog & other)
{
	if (this->Dogptr)
		delete Dogptr;
	this->_type = other.getType();
	this->Dogptr = new Brain(*other.Dogptr);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Gav-Gav" << std::endl;
}
