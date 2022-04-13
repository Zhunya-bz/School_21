#ifndef CPP_FIXED_H
#define CPP_FIXED_H

#include <iostream>

class Fixed
{
private:
	int					_value;
	static const int	_bit = 8;
public:
	Fixed();
	~Fixed();

	Fixed(const Fixed &obj); // конструктор копирования

	Fixed & operator=(const Fixed &obj); // перегрузка оператора присваивания =

	int getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif //CPP_FIXED_H
