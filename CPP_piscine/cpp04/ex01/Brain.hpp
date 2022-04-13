#ifndef CPP_BRAIN_HPP
#define CPP_BRAIN_HPP

#include <iostream>

class Brain
{
protected:
	std::string	ideas[100];

public:
	Brain();
	~Brain();
	Brain(const Brain & copy);

//	void setIdeas(Brian & brian);

	Brain & operator= (const Brain & other);

};

//std::ostream& operator<< (std::ostream &out, const Brain &animal);


#endif //CPP_BRAIN_HPP
