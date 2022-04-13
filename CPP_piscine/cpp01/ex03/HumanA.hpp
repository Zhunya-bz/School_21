#ifndef CPP_HUMANA_HPP
#define CPP_HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon		&Weap;
public:
	HumanA(std::string name, Weapon &Weap);
	~HumanA();

	void setName(std::string name);
	std::string getName();

	void attack();
};

#endif //CPP_HUMANA_HPP
