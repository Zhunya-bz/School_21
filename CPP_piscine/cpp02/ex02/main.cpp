#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//	Fixed b(5);

	std::cout <<"a = " << a << std::endl;
	std::cout <<"b = " << b << std::endl;

	bool rez = a == b;
	std::cout << "a == b : \t"<< rez << std::endl;
	rez = a != b;
	std::cout << "a != b : \t" << rez << std::endl;
	rez = a > b;
	std::cout << "a > b : \t" << rez << std::endl;
	a = 6.6f;
	std::cout <<"a = \t\t" << a << std::endl;
	std::cout <<"b = \t\t" << b << std::endl;
	rez = a == b;
	std::cout << "a == b : \t" << rez << std::endl;

	Fixed c = a + b;
	std::cout << "a + b : \t" << c << std::endl;
	c = a - b;
	std::cout << "a - b : \t" << c << std::endl;
//	a = 324354354;
//	b = 0.23425f;
	c = a * b;
	std::cout << "a * b : \t" << c << std::endl;
	c = a / b;
	std::cout << "a / b : \t" << c << std::endl;

	a = 6;
	std::cout << "a : \t" << a << std::endl;
	std::cout << "++a: \t" << ++a << std::endl;

	std::cout << "a : \t" << a << std::endl;
	std::cout << "a++: \t" << a++ << std::endl;
	std::cout << "a : \t" << a << std::endl;
//
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//
	Fixed const k(2.3f);
	std::cout << "a = " << a << " b = " << b << " k = " << k <<std::endl;
	std::cout << "max(k,b): \t" << Fixed::max( k, b ) << std::endl;
	std::cout << "min(a,b): \t" << Fixed::min( a, b ) << std::endl;
	return 0;
}