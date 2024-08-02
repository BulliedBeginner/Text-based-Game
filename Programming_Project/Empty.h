#pragma once
#include "Item.h"
class Empty : public Item
{
public:
	Empty();
	~Empty();

	void printDetail();
	void printName();
	int Get_Damage();
};

