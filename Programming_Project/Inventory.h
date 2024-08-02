#pragma once
#include <iostream>
#include "Empty.h"
#include "Weapon.h"
#include "Armor.h"

class Inventory
{
public:
	Inventory();
	~Inventory();
	Item* _array[5] = {new Empty(), new Empty(), new Empty() ,new Empty(), new Empty()};
	int _index;

	Inventory& operator++();
	Inventory operator++(int);
	Inventory& operator--();
	Inventory operator--(int);
	Item& operator*();
	void operator=(Item right);

	void addItem(Item *item);
	void print();
	void linePrint();
	void checkActiveItem();
};

