#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point a(3, -3);
	Point b(5,5);
	Point c(7, -3);
	Point point(5, -3);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	std::cout << bsp(a,b,c,point) << std::endl;

//	Point a(3.0f, 1.0f);
//	Point b(-6.5f, 6.4f);
//	Point c(-2.0f, -4.0f);
//	Point point(2.9f, 1.0f);
//
//	std::cout << bsp(a, b, c, point) << std::endl;

	return 0;
}