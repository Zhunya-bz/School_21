#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure & copy) : AMateria(copy._type)
{
	(*this) = copy;
}

Cure & Cure::operator= (const Cure & copy)
{
	if (this != &copy) {
		this->_type = copy._type;
	}
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria *clone = new Cure();
	return (clone);
}

void Cure::use(ICharacter& target)
{
	std::cout << BLUE << "* heals "<< target.getName() << "’s wounds *" << RESET << std::endl;
}