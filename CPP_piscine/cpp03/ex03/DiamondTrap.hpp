#ifndef CPP_DIAMONDTRAP_HPP
#define CPP_DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	~DiamondTrap();

	DiamondTrap(std::string name);

	std::string getName() const;
	int 		getPoints() const;
	int 		getEnergy() const;
	int 		getDamage() const;

	DiamondTrap(DiamondTrap & copy);
	DiamondTrap & operator= (DiamondTrap & other);

	void whoAmI();
	void attack(std::string const & target);

};

std::ostream& operator<< (std::ostream &out, const DiamondTrap &st);

#endif //CPP_DIAMONDTRAP_HPP
