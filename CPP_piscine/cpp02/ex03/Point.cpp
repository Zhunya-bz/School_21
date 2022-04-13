#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(const float floatX, const float floatY): x(floatX), y(floatY)
{}

Point::~Point()
{}

Point::Point(Point const &obj)
{
	*this = obj;
}

Point & Point::operator= (Point const & obj)
{
	const_cast<Fixed &>(this->x) = obj.getX();
	const_cast<Fixed &>(this->y) = obj.getY();
	return (*this);
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

std::ostream& operator<< (std::ostream &out, const Point &p)
{
	out << "x = " << p.getX() << " y = " << p.getY();
	return (out);
}
