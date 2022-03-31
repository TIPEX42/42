#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	Zombie *zombies = zombieHorde(10, "horde zombie");

	for (int i = 0; i < 10; i++)
		zombies[i].annouce();

	delete[] zombies;
}