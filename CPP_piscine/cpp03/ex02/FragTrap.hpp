#ifndef CPP_FRAGTRAP_HPP
#define CPP_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	~FragTrap();

	FragTrap(std::string name);

	FragTrap(FragTrap & copy);
	FragTrap & operator= (FragTrap & other);

	void highFivesGuys(void);
};


#endif //CPP_FRAGTRAP_HPP
