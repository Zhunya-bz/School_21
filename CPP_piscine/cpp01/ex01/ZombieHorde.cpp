#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *arr_zom;

	arr_zom = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		arr_zom[i].set_name(name);
	}
	return (arr_zom);
}
