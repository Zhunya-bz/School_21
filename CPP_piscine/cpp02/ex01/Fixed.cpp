#include "Fixed.hpp"

Fixed::Fixed() : _bitValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

void toBin(int digit)
{
	char binary[50];
	int count = 0;
	do
	{
		if (count == 8)
		{
			binary[count++] = '.';
			continue;
		}
		if(digit % 2)
			binary[count++] = '1';
		else
			binary[count++] = '0';
		digit=digit/2;
	} while(count < 32);
	binary[count++] = '\0';
	for(int i = strlen(binary); i>0; i--)
		std::cout << binary[i - 1];
	std::cout<<std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
//	toBin(value);
	_bitValue = value << _bit; // сдвигаем на 8 бит влево
//	toBin(_bitValue);
//	std::cout <<_bitValue<<std::endl; // число Int, которое сдвинули на 8 бит влево
}

int Fixed::toInt(void) const
{
	return (_bitValue >> _bit); // сдвигаем обратно вправо
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;

//	int k2 = 1 << Fixed::_bit; // 1 - это 00000001, сдвигаем на 8 бит получаем 100000000
//	toBin(k2);
//	float rez = (float)k2;
//	std::cout <<"rez="<< rez <<std::endl;
//	std::cout <<"rez*value="<< rez*value <<std::endl;
//	toBin(std::roundf(rez*value));

	_bitValue = (int)(std::roundf(value * (float)(1 << Fixed::_bit)));
//	std::cout <<"bitVal = "<< _bitValue <<std::endl;
}

float Fixed::toFloat() const
{
//	std::cout << _bitValue <<std::endl;
	float k = (float)(_bitValue) / (float)(1 << _bit);
//	std::cout <<"K="<< k <<std::endl;
	return k;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std:: cout << "Copy constructor called" <<std::endl;
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
	std::cout << "setRawBits member function called" << std::endl;
	_bitValue = raw;
}

Fixed & Fixed::operator=(const Fixed &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	_bitValue = obj.getRawBits();
	return (*this);
}

std::ostream& operator<< (std::ostream &out, const Fixed &fix)
{
	out << (float)(fix.getRawBits()) / (float)(1 << fix.getBit());
	return (out);
}
