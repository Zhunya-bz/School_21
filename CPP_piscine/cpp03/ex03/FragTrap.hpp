#ifndef CPP_FRAGTRAP_HPP
#define CPP_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
protected:
	int _hitpoints;
	int _damage;

public:
	FragTrap();
	~FragTrap();

	FragTrap(std::string name);

	std::string getName() const;
	int 		getPoints() const;
	int 		getEnergy() const;
	int 		getDamage() const;

	FragTrap(FragTrap & copy);
	FragTrap & operator= (FragTrap & other);

	void highFivesGuys(void);
};


#endif //CPP_FRAGTRAP_HPP
