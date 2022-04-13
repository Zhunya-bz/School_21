#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <cstring>

class Weapon
{
private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon();

	const std::string &getType();
	void setType(std::string value);
};

#endif //CPP_WEAPON_HPP
