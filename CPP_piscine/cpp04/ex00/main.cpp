#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();

	std::cout << "Type Dog: " << j->getType() << " " << std::endl;
	std::cout << "Type Cat: " << i->getType() << " " << std::endl;
	std::cout << "Type WrongCat: " << k->getType() << " " << std::endl << std::endl;

	std::cout << "myDog: ";
	j->makeSound();

	std::cout << "myCat: ";
	i->makeSound();

	std::cout << "myWrongCat: ";
	k->makeSound();

	std::cout << "myMetaClass: ";
	meta->makeSound();

	std::cout << std::endl;
	delete j;
	delete i;
	delete k;
	delete meta;

	return (0);
}