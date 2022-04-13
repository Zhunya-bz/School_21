#ifndef CPP_KAREN_HPP
#define CPP_KAREN_HPP

#include <iostream>

class Karen
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void (Karen::*arr[4])(void); // указатель на метод
	// обязательно скобки! указатель на массив, в 2х скобках принимаемые значения метода

public:
	Karen();
	~Karen();

	void complain(std::string level);
};


#endif //CPP_KAREN_HPP
