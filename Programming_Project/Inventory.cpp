#include "Inventory.h"
Inventory::Inventory() {
	_index = 0;
}

Inventory::~Inventory() {}

Item& Inventory::operator*() {
	return *_array[_index];
}

Inventory& Inventory::operator++() {
	if (_index < 5) {
		//_array_pointer++;
		_index++;
	}
	return *this;
}

Inventory Inventory::operator++(int) {
	if (_index < 5) {
		//++_array_pointer;
		_index++;
	}
	return *this;

}

Inventory& Inventory::operator--() {
	if (_index >= 0) {
		//_array_pointer--;
		_index--;
	}
	return *this;

}

Inventory Inventory::operator--(int) {
	if (_index >= 0) {
		//--_array_pointer;
		_index--;
	}
	return *this;

}

void Inventory::operator=(Item right) {
	*_array[_index] = right;
}

void Inventory::addItem(Item *item) {
	int i = 0;
	for (; i < 5; i++) {
		if (_array[i]->_itemType == empty) {
			_array[i] = item;
			return;
		}
	}
}

void Inventory::print() {
	std::cout << "Inventory:\n";
	for (auto& x : _array) {
		x->printName();	
		std::cout << "\n";
	}
}

void Inventory::linePrint() {
	std::cout << "Inventory:";
	for (auto& x : _array) {
		if (x->_isEquip) {
			x->printName();
			std::cout << "(A)";
			std::cout << "   ";
		}
		else {
			x->printName();
			std::cout << "   ";
		}
	}
}

void Inventory::checkActiveItem() {

}