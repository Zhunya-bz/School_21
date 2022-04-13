#include "ClapTrap.hpp"

int main()
{
	ClapTrap one("Zhenya");
	ClapTrap two;
	ClapTrap three(one);

	one.attack("yuuuhhhh");
	one.takeDamage(3);
	one.beRepaired(1);
	return (0);
}