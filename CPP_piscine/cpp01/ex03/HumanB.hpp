#ifndef CPP_HUMANB_HPP
#define CPP_HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *Weap;
public:
	HumanB(std::string name);
	~HumanB();

	void setName(std::string name);
	std::string getName();

	void setWeapon(Weapon &Weap);

	void attack();
};

#endif //CPP_HUMANB_HPP
