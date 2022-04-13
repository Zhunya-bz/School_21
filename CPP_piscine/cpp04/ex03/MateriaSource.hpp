#ifndef CPP_MATERIASOURCE_HPP
#define CPP_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_source[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource & copy);
	MateriaSource & operator= (MateriaSource const & copy);

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);
};


#endif //CPP_MATERIASOURCE_HPP
