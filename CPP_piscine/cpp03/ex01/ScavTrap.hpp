#ifndef CPP_SCAVTRAP_HPP
#define CPP_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();

	ScavTrap(std::string name);

	ScavTrap(ScavTrap & copy);
	ScavTrap & operator= (ScavTrap & other);

	void	guardGate();
	void	attack(std::string const & target);
};

std::ostream& operator<< (std::ostream &out, const ScavTrap &st);

#endif //CPP_SCAVTRAP_HPP
