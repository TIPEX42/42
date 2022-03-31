//
// Created by Nathan Jennes on 3/31/22.
//

#include <iostream>
#include "HumanA.h"
#include "Weapon.h"


HumanA::HumanA()
	:m_Name("HumanA"), m_Weapon(nullptr)
{

}

HumanA::HumanA(const std::string &name, Weapon &weapon)
	:m_Name(name), m_Weapon(&weapon)
{

}

HumanA::HumanA(const HumanA &other)
	:m_Name(other.m_Name), m_Weapon(other.m_Weapon)
{
}

HumanA &HumanA::operator=(const HumanA &other)
{
	if (this == &other)
		return *this;

	m_Weapon = other.m_Weapon;
	m_Name = other .m_Name;
	return *this;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << m_Name << " attacks with their weapon " << m_Weapon->GetType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
	m_Weapon = &weapon;
}
