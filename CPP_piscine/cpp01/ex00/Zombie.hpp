#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string name_zombie);
	~Zombie();
//	void		set_name(std::string name);
	std::string get_name();
	void		announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif //CPP_ZOMBIE_HPP
