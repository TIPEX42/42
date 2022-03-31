//
// Created by Nathan Jennes on 3/31/22.
//

#ifndef HUMANA_H
#define HUMANA_H

#include <string>

class Weapon;

class HumanA
{
public:
	HumanA();
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();
	HumanA(const HumanA &other);
	HumanA &operator=(const HumanA &other);

	void attack();
	void setWeapon(Weapon &weapon);

private:
	Weapon *m_Weapon;
	std::string m_Name;

};


#endif //HUMANA_H
