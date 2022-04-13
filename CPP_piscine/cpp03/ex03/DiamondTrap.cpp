#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): FragTrap(), ScavTrap(), _name("Noname")
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_damage = FragTrap::_damage;
	ClapTrap::_name = "Noname_clap_trap";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap Constructor called " << name << std::endl;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy_points = ScavTrap::_energy_points;
	this->_damage = FragTrap::_damage;
//	std::cout << this->_hitpoints <<" " << this->_energy_points <<" "<< this->_damage<<std::endl;
	ClapTrap::_name = name + "_clap_trap";
}

DiamondTrap::DiamondTrap(DiamondTrap &copy) : FragTrap(copy), ScavTrap(copy), _name(copy._name)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	(*this) = copy;
}

DiamondTrap & DiamondTrap::operator= (DiamondTrap & other)
{
	this->_name = other.getName();
	this->_hitpoints = other.getPoints();
	this->_energy_points = other.getEnergy();
	this->_damage = other.getDamage();
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << _name << " from Diamond" << std::endl;
	std::cout << "I am " << ClapTrap::_name << " from Clap" << std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

std::ostream& operator<< (std::ostream &out, const DiamondTrap &st)
{
	out << st.getName() << " " << st.getPoints() << " " << st.getEnergy() << " " << st.getDamage();
	return (out);
}

std::string DiamondTrap::getName() const
{
	return (this->_name);
}

int 		DiamondTrap::getPoints() const
{
	return (this->_hitpoints);
}

int 		DiamondTrap::getEnergy() const
{
	return (this->_energy_points);
}

int 		DiamondTrap::getDamage() const
{
	return (this->_damage);
}
