#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}


Brain::Brain(const Brain & copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	(*this) = copy;
}

Brain & Brain::operator= (const Brain & other)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
	return (*this);
}

//std::string Brain::getType() const
//{
//	return (this->_type);
//}

//std::ostream& operator<< (std::ostream &out, const Brain &animal)
//{
//	out << animal.getType();
//	return (out);
//}

//void Brain::makeSound() const
//{
//	std::cout << "Brain" << std::endl;
//}