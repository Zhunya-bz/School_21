#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
//	std::cout << "Constructor called" << std::endl;
	_type = type;
}

Weapon::~Weapon()
{
//	std::cout << "Destructor called" << std::endl;
}

void Weapon::setType(std::string value)
{
	this->_type = value;
}

const std::string &Weapon::getType()
{
	return (this->_type);
}