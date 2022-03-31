//
// Created by Nathan Jennes on 3/31/22.
//

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
public:
	Weapon();
	Weapon(const std::string &type);
	~Weapon();
	Weapon(const Weapon &other);
	Weapon &operator=(const Weapon &other);

	std::string GetType() const;
	void SetType(const std::string &type);

private:
	std::string m_Type;
};


#endif //WEAPON_H
