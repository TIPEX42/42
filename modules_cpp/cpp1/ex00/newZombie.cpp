#include "newZombie.h"
#include "Zombie.h"

Zombie *newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name);
	return newZombie;
}

void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.annouce();
}
