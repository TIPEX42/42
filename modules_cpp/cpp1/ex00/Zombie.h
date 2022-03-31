//
// Created by Nathan Jennes on 3/31/22.
//

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>


class Zombie
{
public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();
	Zombie(const Zombie &other);
	Zombie &operator=(const Zombie &other);

	void annouce();

private:
	std::string m_Name;
};


#endif //ZOMBIE_H
