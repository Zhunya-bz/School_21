#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Noname"), _hitpoints(10), _energy_points(10), _damage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10),	_energy_points(10), _damage(0)
{
	std::cout << "ClapTrap Constructor called " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hit, int energy, int damage):  _name(name), _hitpoints(hit),
			_energy_points(energy), _damage(damage)
{
	std::cout << "ClapTrap Constructor called " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	(*this) = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called " << this->_name << std::endl;
}

ClapTrap & ClapTrap::operator= (const ClapTrap & other)
{
	this->_name = other.getName();
	this->_hitpoints = other.getPoints();
	this->_energy_points = other.getEnergy();
	this->_damage = other.getDamage();
	return (*this);
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

int 		ClapTrap::getPoints() const
{
	return (this->_hitpoints);
}
int 		ClapTrap::getEnergy() const
{
	return (this->_energy_points);
}
int 		ClapTrap::getDamage() const
{
	return (this->_damage);
}

void ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_damage <<
		" points of damage!" <<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name
	<< " take " << amount << " point of damage!"
	<< std::endl;

	this->_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name
	<< " repaired by " << amount << " health points."
	<< std::endl;
	this->_hitpoints += amount;
}