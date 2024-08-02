#include "Empty.h"
Empty::Empty() {
	_itemType = empty;
	_isEquip = false;
}

Empty::~Empty() {}

void Empty::printDetail() {
	std::cout << "Empty\n";
}

void Empty::printName() {
	std::cout << "Empty";
}

int Empty::Get_Damage() {
	return 0;
}