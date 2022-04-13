#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Noname", 100, 100, 30)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap Constructor called " << name << std::endl;
}

FragTrap::FragTrap(FragTrap &copy)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	(*this) = copy;
}

FragTrap & FragTrap::operator= (FragTrap & other)
{
	this->_name = other.getName();
	this->_hitpoints = other.getPoints();
	this->_energy_points = other.getEnergy();
	this->_damage = other.getDamage();
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High fives!" << std::endl;
}
