#include <iostream>

int main(void) {
	int i = -1;
	extern char **environ;

	std::cout << "Content-type: text/plain";
	std::cout << "\r\n\r\n";
	while (environ[++i]) {
		std::cout << environ[i] << std::endl;
	}
	return 0;
}
