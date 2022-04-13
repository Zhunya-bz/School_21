#include "Zombie.hpp"

int main()
{
	int N = 5;

	Zombie *arr = zombieHorde(N,"Zhunya"); // выделение памяти и заполнение

	for (int i = 0; i < N; ++i)
		arr[i].announce(); //проверка что выделилось)

	delete[] arr;

	return (0);
}

