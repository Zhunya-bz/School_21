#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;

public:
	Contact(); // constructor
//	Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret);
	~Contact(); //destructor
	std::string get_first_name(); // получить значение
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_secret();
	void 		set_first_name(std::string value); // присвоить значение
	void 		set_last_name(std::string value);
	void 		set_nickname(std::string value);
	void 		set_phone_number(std::string value);
	void 		set_secret(std::string value);

};

#endif //CPP00_CONTACT_HPP
