#ifndef CPP_ANIMAL_HPP
#define CPP_ANIMAL_HPP

#include <iostream>
#include <string>

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
	virtual void makeSound() const;
};

std::ostream& operator<< (std::ostream &out, const Animal &animal);


#endif //CPP_ANIMAL_HPP
