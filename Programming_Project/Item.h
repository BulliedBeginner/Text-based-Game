#pragma once
#include <iostream>
enum ItemType {
	weapon,
	armor,
	empty
};

class Item
{
public:
	bool _isEquip;
	int _price;
	ItemType _itemType;

	virtual void printName();
	virtual void printDetail();
	virtual std::string Get_Name();
	virtual int Get_Damage();
};

