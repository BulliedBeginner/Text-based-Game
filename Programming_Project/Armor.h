#pragma once
#include "Item.h"
enum ArmorType{
	IronArmor,
	DiamondArmor
};

class Armor : public Item
{
public:
	ArmorType _type;
	int _damageDecrease;

	Armor();
	Armor(ArmorType type, bool isEquip);
	~Armor();

	void broken();
	void printDetail();
	void printName();
	std::string Get_Name();
	int Get_Damage();
};

