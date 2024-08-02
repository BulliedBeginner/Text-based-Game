#include "Weapon.h"
Weapon::Weapon() {
	_isEquip = false;
	_type = IronSword;
	_damageIncrease = 20;
	_price = 10;
	_itemType = weapon;
}

Weapon::Weapon(WeaponType type, bool isEquip) {
	_isEquip = isEquip;
	_type = type;
	_itemType = weapon;

	if (_type == IronSword) {
		_damageIncrease = 20;
		_price = 30;
	}

	if (_type == DiamondSword) {
		_damageIncrease = 25;
		_price = 40;
	}
}

Weapon::~Weapon() {}

void Weapon::broken() {
	std::cout << "Weapon broken\nPlease swap another weapon.";
	_damageIncrease = 0;
}

void Weapon::printDetail() {
	std::string sword = "";
	if (_type == IronSword) sword = "Iron Sword";
	if (_type == DiamondSword) sword = "Diamond Sword";

	std::cout << "Weapon: \n";
	std::cout << "Type: " << sword << "\n";
	std::cout << "Equip status: " << _isEquip ? "Yes\n" : "No\n";
}

void Weapon::printName() {
	std::string sword = "";
	if (_type == IronSword) sword = "Iron Sword";
	if (_type == DiamondSword) sword = "Diamond Sword";
	std::cout << sword;
}

std::string Weapon::Get_Name() {
	std::string sword = "";
	if (_type == IronSword) sword = "Iron Sword";
	if (_type == DiamondSword) sword = "Diamond Sword";
	return sword;
}

int Weapon::Get_Damage() {
	return _damageIncrease;
}
