#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
//	std::cout << "Constructor called" << std::endl;
}

HumanB::~HumanB()
{
//	std::cout << "Destructor called" << std::endl;
}

std::string HumanB::getName()
{
	return (_name);
}

void HumanB::setName(std::string name)
{
	this->_name = name;
}

void HumanB::setWeapon(Weapon &Weap)
{
	this->Weap = &Weap;
}

void HumanB::attack()
{
	for (std::string::size_type i = 0; i < _name.length(); i++)
	{
		std::cout << static_cast<char>(std::toupper(_name[i]));
	}
	if (Weap == NULL)
		std::cout << " has no weapon" << std::endl;
	else
		std::cout << " attacks with his " << this->Weap->getType() << std::endl;
}