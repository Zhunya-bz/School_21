#include "Fixed.hpp"

Fixed::Fixed() : _bitValue(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
//	std::cout << "Int constructor called" << std::endl;
	_bitValue = value << _bit; // сдвигаем на 8 бит влево
}

int Fixed::toInt(void) const
{
	return (_bitValue >> _bit); // сдвигаем обратно вправо
}

Fixed::Fixed(const float value)
{
//	std::cout << "Float constructor called" << std::endl;
	_bitValue = (int)(std::roundf(value * (float)(1 << Fixed::_bit)));
}

float Fixed::toFloat() const
{
	float k = (float)(_bitValue) / (float)(1 << _bit);
	return k;
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
//	std:: cout << "Copy constructor called" <<std::endl;
	*this = obj;
}

int Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_bitValue);
}

int 	Fixed::getBit(void) const
{
	return (this->_bit);
}

void Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called" << std::endl;
	_bitValue = raw;
}

Fixed & Fixed::operator=(const Fixed &obj)
{
//	std::cout << "Assignation operator called" << std::endl;
	_bitValue = obj.getRawBits();
	return (*this);
}

Fixed & Fixed::operator= (double const &floating)
{
	this->_bitValue = (int)(std::roundf( ((double)floating * (double)(1 << Fixed::_bit))));
	return (*this);
}

Fixed & Fixed::operator= (int const &integer)
{
	this->_bitValue = integer << (Fixed::_bit);
	return (*this);
}

std::ostream& operator<< (std::ostream &out, const Fixed &fix)
{
	out << (float)(fix.getRawBits()) / (float)(1 << fix.getBit());
	return (out);
}

bool Fixed::operator== (const Fixed & right)
{
	return (this->getRawBits() == right.getRawBits());
}

bool Fixed::operator!= (const Fixed & right)
{
	return (!(this->getRawBits() == right.getRawBits()));
}

bool Fixed::operator> (const Fixed & right)
{
	return (this->getRawBits() > right.getRawBits());
}

bool Fixed::operator< (const Fixed & right)
{
	return (this->getRawBits() < right.getRawBits());
}

bool Fixed::operator>= (const Fixed & right)
{
	return (this->getRawBits() >= right.getRawBits());
}

bool Fixed::operator<= (const Fixed & right)
{
	return (this->getRawBits() <= right.getRawBits());
}

Fixed Fixed::operator+ (const Fixed & right)
{
	Fixed result;

	result.setRawBits(this->getRawBits() + right.getRawBits());
	return (result);
}

Fixed Fixed::operator- (const Fixed & right)
{
	Fixed result;

	result.setRawBits(this->getRawBits() - right.getRawBits());
	return (result);
}

Fixed Fixed::operator* (const Fixed & right)
{
	Fixed result;
	long long buf;

	buf = (long)this->getRawBits() * (long)right.getRawBits();
	result.setRawBits(buf >> Fixed::_bit);
	return (result);
}

Fixed Fixed::operator/ (const Fixed & right)
{
	Fixed result;
	long long buf;

	buf = this->getRawBits();
	buf = buf << Fixed::_bit;
	buf /= right.getRawBits();
	result.setRawBits(buf);
	return (result);
}

Fixed & Fixed::operator++ () // префикс
{
	this->_bitValue++;
	return (*this);
}

Fixed Fixed::operator++ (int) // постфикс
{
	Fixed tmp(*this);

	this->_bitValue++;
	return (tmp);
}

Fixed & Fixed::operator-- () // префикс
{
	this->_bitValue--;
	return (*this);
}

Fixed Fixed::operator-- (int) // постфикс
{
	Fixed tmp(*this);

	this->_bitValue--;
	return (tmp);
}

Fixed & Fixed::min(Fixed & one, Fixed & two)
{
	if (one.getRawBits() > two.getRawBits())
		return (two);
	return (one);
}

Fixed & Fixed::max(Fixed & one, Fixed & two)
{
	if (one.getRawBits() > two.getRawBits())
		return (one);
	return (two);
}

const Fixed & Fixed::min(const Fixed & one, const Fixed & two)
{
	if (one.getRawBits() > two.getRawBits())
		return (two);
	return (one);
}

const Fixed & Fixed::max(const Fixed & one, const Fixed & two)
{
	if (one.getRawBits() > two.getRawBits())
		return (one);
	return (two);
}