#ifndef CPP_FIXED_H
#define CPP_FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_bitValue;
	static const int	_bit = 8;

public:
	Fixed();
	~Fixed();

	Fixed(const int value); // Int конструктор
	Fixed(const float value); // Float конструктор
	Fixed(const Fixed &obj); // конструктор копирования

	Fixed & operator=(const Fixed &obj); // перегрузка оператора присваивания =

	bool operator== (const Fixed & right);
	bool operator!= (const Fixed & right);
	bool operator> (const Fixed & right);
	bool operator< (const Fixed & right);
	bool operator>= (const Fixed & right);
	bool operator<= (const Fixed & right);

	int		getRawBits(void) const;
	int 	getBit(void) const;
	void	setRawBits(int const raw);

	int		toInt(void) const; // конвертация в Int
	float	toFloat(void) const; // конвертация в float
};

std::ostream& operator<< (std::ostream &out, const Fixed &fix); // перегруженный оператор вывода

#endif //CPP_FIXED_H
