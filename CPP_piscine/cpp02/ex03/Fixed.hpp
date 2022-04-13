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

	Fixed & operator= (const Fixed &obj); // перегрузка оператора присваивания =
	Fixed & operator= (double const &floating);
	Fixed & operator= (int const &integer);

	bool operator== (const Fixed & right); // перегрузка опрераторов сравнения
	bool operator!= (const Fixed & right);
	bool operator> (const Fixed & right);
	bool operator< (const Fixed & right);
	bool operator>= (const Fixed & right);
	bool operator<= (const Fixed & right);

	Fixed operator+ (const Fixed & right); // перегрузка математических операторов
	Fixed operator- (const Fixed & right);
	Fixed operator* (const Fixed & right);
	Fixed operator/ (const Fixed & right);

	Fixed & operator++ (); // префикс
	Fixed operator++ (int);// постфикс
	Fixed & operator-- ();
	Fixed operator-- (int);

	static Fixed & min(Fixed & one, Fixed & two);
	static Fixed & max(Fixed & one, Fixed & two);
	static const Fixed & min(const Fixed & one, const Fixed & two);
	static const Fixed & max(const Fixed & one, const Fixed & two);

	int		getRawBits(void) const;
	int 	getBit(void) const;
	void	setRawBits(int const raw);

	int		toInt(void) const; // конвертация в Int
	float	toFloat(void) const; // конвертация в float
};

std::ostream& operator<< (std::ostream &out, const Fixed &fix);

#endif //CPP_FIXED_H
