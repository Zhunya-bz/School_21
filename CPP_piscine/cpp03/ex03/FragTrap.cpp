#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_hitpoints = 100;
//	this->_energy_points = 100;
	this->_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor called " << name << std::endl;
	this->_hitpoints = 100;
//	this->_energy_points = 100;
	this->_damage = 30;
	this->_name = name;
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

std::string FragTrap::getName() const
{
	return (this->_name);
}

int 		FragTrap::getPoints() const
{
	return (this->_hitpoints);
}

int 		FragTrap::getEnergy() const
{
	return (this->_energy_points);
}

int 		FragTrap::getDamage() const
{
	return (this->_damage);
}