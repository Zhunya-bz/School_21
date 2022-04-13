#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	Catptr = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
	delete Catptr;
}

Cat::Cat(const Cat & copy) : Animal(copy)
{
	std::cout << "Cat copy constructor" << std::endl;
	Catptr = new Brain();
	(*this) = copy;
}

Cat & Cat::operator= (const Cat & other)
{
//	std::cout << this->Catptr << std::endl;
	if (this->Catptr)
		delete Catptr;
	this->_type = other.getType();
	this->Catptr = new Brain(*other.Catptr);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meoooow" << std::endl;
}