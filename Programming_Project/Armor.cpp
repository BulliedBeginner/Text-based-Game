#include "Armor.h"
Armor::Armor() {
	_isEquip = false;
	_type = IronArmor;
	_damageDecrease = 10;
	_price = 10;
	_itemType = armor;
}

Armor::Armor(ArmorType type, bool isEquip) {
	_type = type;
	_isEquip = isEquip;
	_itemType = armor;

	if (_type == IronArmor) {
		_damageDecrease = 5;
		_price = 30;
	}

	if (_type == DiamondArmor) {
		_damageDecrease = 10;
		_price = 60;
	}
}

Armor::~Armor() {}

void Armor::broken() {
	std::cout << "Armor broken\nPlease swap another armor.";
	_damageDecrease = 0;
}

void Armor::printDetail() {
	std::string armor = "";
	if (_type == IronArmor) armor = "Iron armor";
	if (_type == DiamondArmor) armor = "Diamond armor";

	std::cout << "Armor: \n";
	std::cout << "Type: " << armor << "\n";
	std::cout << "Equip status: " << _isEquip ? "Yes\n" : "No\n";
}

void Armor::printName() {
	std::string armor = "";
	if (_type == IronArmor) armor = "Iron armor";
	if (_type == DiamondArmor) armor = "Diamond armor";
	std::cout << armor;
}

std::string Armor::Get_Name() {
	std::string armor = "";
	if (_type == IronArmor) armor = "Iron armor";
	if (_type == DiamondArmor) armor = "Diamond armor";
	return armor;
}

int Armor::Get_Damage() {
	return _damageDecrease;
}