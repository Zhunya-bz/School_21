#ifndef CPP_ICE_HPP
#define CPP_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice & copy);
	Ice & operator= (const Ice & copy);

	AMateria* clone() const;
	void use(ICharacter& target);
};


#endif //CPP_ICE_HPP
