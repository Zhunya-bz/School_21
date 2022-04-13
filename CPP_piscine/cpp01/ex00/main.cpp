#include "Zombie.hpp"

int main()
{
	Zombie *my = newZombie("Zhunya");// на куче через функцию
	my->announce();
	delete my; // удаление Жуни

	randomChump("BOB"); // на стеке выделяется зомби

	Zombie two("Vadim");//на стеке тоже самое что делает randomChump
//	two.set_name("as");
	two.announce();
	return (0);
}

