#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap one("Zhenya");
	std::cout << one <<std::endl;
	std::cout << std::endl;

	DiamondTrap two("Andrey");
	std::cout << two <<std::endl;
	std::cout << std::endl;

	DiamondTrap three(two);
	std::cout << three <<std::endl;
	std::cout << std::endl;

	two.whoAmI();
	two.attack("bum!");
	two.highFivesGuys();
	two.takeDamage(5);
	one.attack("vjuhh");
	one.guardGate();
	std::cout << std::endl;

	return (0);
}