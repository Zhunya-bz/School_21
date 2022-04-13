#include "Fixed.hpp"

int main(void)
{
	Fixed a;   //default constructor
	Fixed b(a);//copy constructor and assignation operator
	Fixed c;   //default constructor

	c = b; //assignation operator

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}