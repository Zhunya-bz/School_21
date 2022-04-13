#ifndef CPP_WRONGANIMAL_HPP
#define CPP_WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string	_type;

public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal & copy);

	WrongAnimal & operator= (const WrongAnimal & other);

	std::string getType() const;
	void makeSound() const;
};

std::ostream& operator<< (std::ostream &out, const WrongAnimal &animal);

#endif //CPP_WRONGANIMAL_HPP
