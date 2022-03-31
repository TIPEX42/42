//
// Created by Nathan Jennes on 3/31/22.
//

#ifndef HUMANB_H
#define HUMANB_H

#include <string>
class Weapon;

class HumanB
{
public:
	HumanB();
	HumanB(const std::string &name);
	~HumanB();
	HumanB(const HumanB &other);
	HumanB &operator=(const HumanB &other);

	void attack();
	void setWeapon(Weapon &weapon);

private:
	Weapon &m_Weapon;
	std::string m_Name;

};


#endif //HUMANB_H
