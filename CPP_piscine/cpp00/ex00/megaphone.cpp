#include <iostream>
#include <cctype>
#include <string>
#include <typeinfo>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
		{
			for (size_t j = 0; j < strlen(argv[i]); ++j)
			{
//				std::cout << typeid(argv[i][j]).name();
				std::cout << static_cast<char>(toupper(argv[i][j]));
			}
			std::cout << ' ';
		}
		std::cout << '\n';
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
