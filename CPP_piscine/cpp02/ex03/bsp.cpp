#include "Fixed.hpp"
#include "Point.hpp"

int check(Point const a, Point const b, Point const point)
{
	Fixed res;

	res = ((point.getX() - a.getX()) * (b.getY() - a.getY()) - (point.getY() - a.getY()) * (b.getX() - a.getX()));
	if (res > 0)
		return (1);
	return (0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	int count = 0;

	count = check(a,b,point);
	count += check(b,c,point);
	count += check(c,a,point);
	if (count == 3 || count == 0)
		return (true);
	return (false);
}