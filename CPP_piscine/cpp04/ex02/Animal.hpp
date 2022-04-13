#ifndef CPP_ANIMAL_HPP
#define CPP_ANIMAL_HPP

#include <iostream>
#include <string>

#define GREEN	"\033[0;32m"
#define YELO	"\033[0;33m"
#define BLUE	"\033[0;34m"
#define NEW		"\033[0;35m"
#define DEL	"\033[0m"

class Animal
{
protected:
	std::string	_type;

public:
	Animal();
	virtual ~Animal();
	Animal(std::string type);
	Animal(const Animal & copy);

	Animal & operator= (const Animal & other);

	std::string getType() const;
	virtual void makeSound() const = 0; // чисто виртуальный метод => класс абстрактный => нельзя определять объекты
};

std::ostream& operator<< (std::ostream &out, const Animal &animal);


#endif //CPP_ANIMAL_HPP
