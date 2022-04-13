#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & copy)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	(*this) = copy;
}

void WrongCat::makeSound() const
{
	std::cout << "Meoooow" << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->_type);
}
