#include "Item.h"
void Item::printName() {
	std::cout << "This is an item name\n";
}

void Item::printDetail() {
	std::cout << "This is an item detail\n";
}

std::string Item::Get_Name() {
	return "Item";
}

int Item::Get_Damage() {
	return 0;
}
