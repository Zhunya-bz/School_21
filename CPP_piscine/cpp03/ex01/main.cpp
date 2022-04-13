#include "ScavTrap.hpp"

int main()
{
	ScavTrap one("Zhenya");
	std::cout << std::endl;

	ScavTrap two(one);
	std::cout << two <<std::endl;
	std::cout << std::endl;

	ScavTrap three("Andrey");
	std::cout << std::endl;

	three.attack("Pasta");
	two.takeDamage(5);
	one.attack("vjuhh");
	one.guardGate();
	std::cout << std::endl;

	return (0);
}