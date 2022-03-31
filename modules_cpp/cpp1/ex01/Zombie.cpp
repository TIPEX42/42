//
// Created by Nathan Jennes on 3/31/22.
//

#include "Zombie.h"
#include <iostream>

Zombie::Zombie()
		:m_Name("default zombie")
{
}

Zombie::Zombie(const std::string &name)
		:m_Name(name)
{
}

Zombie::~Zombie()
{
	std::cout << m_Name << ": got deleted!" << std::endl;
}

Zombie::Zombie(const Zombie &other)
	:m_Name(other.m_Name)
{
}

Zombie &Zombie::operator=(const Zombie &other)
{
	if (this == &other)
		return *this;

	m_Name = other.m_Name;
	return *this;
}

void Zombie::annouce()
{
	std::cout << m_Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
