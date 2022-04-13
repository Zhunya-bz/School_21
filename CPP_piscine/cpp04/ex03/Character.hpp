#ifndef CPP_CHARACTER_HPP
#define CPP_CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
protected:
	AMateria	*_materia[4];
	std::string _name;

public:
	Character(std::string name);
	~Character();
	Character(const Character & copy);
	Character & operator= (Character const & copy);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};


#endif //CPP_CHARACTER_HPP
