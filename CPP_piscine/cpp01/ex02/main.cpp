#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN"; // строка
	std::string *stringPTR = &str;        // указатель
	std::string &stringREF = str;         // ссылка

	std::cout << "Address of memory str    : " << &str << std::endl;
	std::cout << "Address of memory str PTR: " << stringPTR << std::endl;
	std::cout << "Address of memory str REF: " << &stringREF << std::endl;

	std::cout << "str    : " << str << std::endl;
	std::cout << "str PTR: " << *stringPTR << std::endl;
	std::cout << "str REF: " << stringREF << std::endl;

//	int a = 5;
//	int &ref_a = a;
//
//	std::cout << ref_a << std::endl;
//	a += 3;
//	std::cout << "a:" << a << std::endl;
//	std::cout << "ref_a:" << ref_a << std::endl;
//	ref_a += 10;
//	std::cout << "a:" << a << std::endl;
//	std::cout << "ref_a:" << ref_a << std::endl;

	return (0);
}

