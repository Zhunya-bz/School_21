#include "Karen.hpp"

int main(int argc, char const *argv[])
{
	Karen person;

	if (argc != 2)
		std::cout << "Error arguments" << std::endl;
	else
		person.complain(argv[1]);

	return (0);
}