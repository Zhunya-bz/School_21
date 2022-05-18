#include "./src/Webserv.hpp"
#include <vector>

//int main()
//{
	// char p[] = " 987\r\n";
	// std::string str;
	// str += p;
	// std::cout << "1: " << str << std::endl;
	// str += " +222";
	// std::cout << "2: " << str << std::endl;
	// std::cout << "check " << p[4] << std::endl;
	// // char *endA;
	// int atoiRes = std::atoi(p + 5);
	// std::cout << "atoi res = " << atoiRes << std::endl;

	// char *pEnd;
	// int num = std::strtol(p, &pEnd, 10);
	// std::cout << "strtol res = " << num << std::endl;

	//decode chunk
	// std::string requst = "header\r\nlength:11\r\n\r\n55\r\none\r\n66\r\n-two\r\n99\r\n-three\r\nd;asdf\r\n-4\r\n0;last\r\n";
	// std::string::size_type headerLen = requst.find("\r\n\r\n");
	// std::string header = requst.substr(0, headerLen + 4);
	// std::string body = requst.substr(headerLen + 4);
	// std::string::size_type p1;
	// std::string::size_type p2;
	// char *pEnd;
	// size_t size = std::strtol(body.c_str(), &pEnd, 16);
	// p1 = 0;
	// while (size != 0)
	// {
	// 	p2 = body.find("\r\n", p1 + 1);
	// 	body.erase(p1, p2 - p1 + 2);
	// 	p1 = body.find("\r\n");
	// 	size = std::strtol(body.c_str() + p1, &pEnd, 16);
	// 	if (size == 0)
	// 		body.erase(p1);
	// }
	// requst = header + body;
	// std::cout << "afrer erase = " << requst << std::endl;

	//check vector with null
//	std::vector<char> s;
//	s.push_back('\0');
//	s.push_back('a');
//	s.push_back('v');
//	s.push_back('\0');
//	std::cout << s[0] << s[1] << s[2] << std::endl;
//	std::cout << "size = " << s.size() << std::endl;
//	return 0;
//}

//int main ()
//{
//	std::vector<int> myvector;
//
//	myvector.push_back(10);
//	std::cout << "myvector contains:" << myvector.back();
//	std::cout << '\n';
//
//	return 0;
//}