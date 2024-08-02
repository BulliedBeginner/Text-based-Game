#pragma once
#include "Item.h"
enum WeaponType {
	IronSword,
	DiamondSword
};

class Weapon : public Item
{
public:
	WeaponType _type;
	int _damageIncrease;

	Weapon();
	Weapon(WeaponType type, bool isEquip);
	~Weapon();

	void broken();
	void printDetail();
	void printName();
	std::string Get_Name();
	int Get_Damage();
};

