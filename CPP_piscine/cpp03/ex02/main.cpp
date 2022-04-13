#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap one("Zhenya");
	std::cout << std::endl;
	FragTrap two("Andrey");
	std::cout << std::endl;

	two.highFivesGuys();
	two.attack("Pasta");
	two.takeDamage(5);
	one.attack("vjuhh");
	one.guardGate();
	std::cout << std::endl;

	return (0);
}