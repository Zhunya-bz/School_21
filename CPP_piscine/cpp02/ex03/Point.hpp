#ifndef CPP_POINT_HPP
#define CPP_POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	~Point();
	Point(Point const & obj);
	Point & operator= (Point const & obj);

	Point(const float floatX, const float floatY);

	Fixed getX() const;
	Fixed getY() const;
};

std::ostream& operator<< (std::ostream &out, const Point &p);
bool	bsp( Point const a, Point const b, Point const c, Point const point);
int		check(Point const a, Point const b, Point const point);

#endif //CPP_POINT_HPP
