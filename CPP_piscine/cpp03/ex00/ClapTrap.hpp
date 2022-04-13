#ifndef CPP_CLAPTRAP_HPP
#define CPP_CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	int 		_hitpoints;
	int 		_energy_points;
	int 		_damage;

public:
	ClapTrap();
	~ClapTrap();

	ClapTrap(std::string name);
	ClapTrap(const ClapTrap & obj);
	ClapTrap & operator= (const ClapTrap & other);

	void 	setName(std::string name);
	void 	setPoint(int point);
	void 	setEnergy(int energy);
	void 	setDamage(int damage);

	std::string getName() const;
	int 		getPoints() const;
	int 		getEnergy() const;
	int 		getDamage() const;

	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};


#endif //CPP_CLAPTRAP_HPP
