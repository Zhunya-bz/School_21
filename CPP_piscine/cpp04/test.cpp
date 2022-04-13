#include <iostream>

class A
{
public:
	int i;
	A(int a):i(a){};
	~A(){};
};

class B : public A
{
public:
	B(int b):A(b){};
	~B(){};
};

int main()
{
	A val1(2);
	B val2(3);

	std::cout << val1.i << "  " << val2.i  << "  " << val1.i << std::endl;
}