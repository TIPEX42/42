#include "Zombie.h"
#include "newZombie.h"

int main()
{
	Zombie z("zombie");
	z.annouce();

	randomChump("zombie2");

	Zombie *zombie = newZombie("zombie3");
	zombie->annouce();
	delete zombie;
}