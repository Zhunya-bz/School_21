#ifndef CPP_IMATERIASOURCE_HPP
#define CPP_IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria* materia) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif //CPP_IMATERIASOURCE_HPP
