#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete _materia[i];
}

Character::Character(const Character & copy)
{
	std::cout << "Character copy" << std::endl;
	(*this) = copy;
}

Character & Character::operator= (Character const & copy)
{
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = copy._materia[i];
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_materia[i])
		{
			_materia[i] = m; // тут лежит указатель на материю (либо лед, либо здоровье)
			std::cout << GREEN << "Put " << i << " " << m->getType() << " in inventory" << RESET << std::endl;
			return ;
		}
	}
	std::cout << RED << "Inventory is full!" << RESET << std::endl;
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << RED << "Wrong index materia" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "Unequip " << idx << " materia: " << _materia[idx]->getType() << RESET << std::endl;
	_materia[idx] = NULL; // тут зануляем потому что материя которая у нас была, мы можем с ней еще работать в
	// дальнейшем, поэтому не delete
}

void Character::use(int idx, ICharacter& target)
{
	if (!_materia[idx])
	{
		std::cout  << RED << "Materia not exist!" << RESET << std::endl;
		return ;
	}
	if (idx > 3 || idx < 0)
	{
		std::cout << RED << "Wrong index materia" << RESET << std::endl;
		return ;
	}
//	std::cout << GREEN << "You use materia " << _materia[idx]->getType() << RESET << std::endl;
	_materia[idx]->use(target); // обращаемся к idx материи, там лежит указатель на материю, и к этой материи
	// применяем метод use
}