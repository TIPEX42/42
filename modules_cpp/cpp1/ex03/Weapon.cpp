
//
// Created by Nathan Jennes on 3/31/22.
//

#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(const std::string &type)
	:m_Type(type)
{
}

Weapon::~Weapon()
{
}

Weapon::Weapon(const Weapon &other)
	:m_Type(other.m_Type)
{
}

Weapon &Weapon::operator=(const Weapon &other)
{
	if (this == &other)
		return *this;

	m_Type = other.m_Type;
	return *this;
}

std::string Weapon::GetType() const
{
	return m_Type;
}

void Weapon::SetType(const std::string &type)
{
	m_Type = type;
}
