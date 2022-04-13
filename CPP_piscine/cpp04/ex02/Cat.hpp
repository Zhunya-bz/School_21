#ifndef CPP_CAT_HPP
#define CPP_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *Catptr;

public:
	Cat();
	~Cat();
	Cat(const Cat & copy);
	Cat & operator= (const Cat & other);

	void makeSound() const;
};


#endif //CPP_CAT_HPP
