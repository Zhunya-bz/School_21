#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Noname", 100, 50, 20)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called " << this->_name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap Constructor called " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &copy)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	(*this) = copy;
}

ScavTrap & ScavTrap::operator= (ScavTrap & other)
{
	this->_name = other.getName();
	this->_hitpoints = other.getPoints();
	this->_energy_points = other.getEnergy();
	this->_damage = other.getDamage();
	return (*this);
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_damage <<
	" points of damage!!!" <<std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode." << std::endl;
}