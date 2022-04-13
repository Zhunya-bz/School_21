#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weap) : _name(name), Weap(Weap)
{
//	std::cout << "Constructor called" << std::endl;
}

HumanA::~HumanA()
{
//	std::cout << "Destructor called" << std::endl;
}

std::string HumanA::getName()
{
	return (_name);
}

void HumanA::setName(std::string name)
{
	this->_name = name;
}

void HumanA::attack()
{
	for (std::string::size_type i = 0; i < _name.length(); i++)
	{
		std::cout << static_cast<char>(std::toupper(static_cast<int>(_name[i])));
	}
	std::cout << " attacks with his " << this->Weap.getType() << std::endl;
}