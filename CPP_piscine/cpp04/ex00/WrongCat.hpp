#ifndef CPP_WRONGCAT_HPP
#define CPP_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();

	WrongCat(const WrongCat & copy);

	std::string getType() const;

	void makeSound() const;
};


#endif //CPP_WRONGCAT_HPP
