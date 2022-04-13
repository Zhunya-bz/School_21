#ifndef CPP_SCAVTRAP_HPP
#define CPP_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
protected:
	int _energy_points;

public:
	ScavTrap();
	~ScavTrap();

	ScavTrap(std::string name);

	std::string getName() const;
	int 		getPoints() const;
	int 		getEnergy() const;
	int 		getDamage() const;

	ScavTrap(ScavTrap & copy);
	ScavTrap & operator= (ScavTrap & other);

	void	guardGate();
	void	attack(std::string const & target);
};


#endif //CPP_SCAVTRAP_HPP
