#ifndef CPP_DOG_HPP
#define CPP_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *Dogptr;

public:
	Dog();
	~Dog();
	Dog(const Dog & copy);
	Dog & operator= (const Dog & other);

	void makeSound() const;
};


#endif //CPP_DOG_HPP
