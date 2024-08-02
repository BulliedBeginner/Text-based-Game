#include "ProtectionLayer.h"
ProtectionLayer::ProtectionLayer() {
	_head_node = nullptr;
	_length = 0;
	_capacity = 2;
}

ProtectionLayer::~ProtectionLayer() {}

bool ProtectionLayer::push(int protection_value) {
	if (_length == _capacity) {
		std::cout << "You cannot have more than " << _capacity << " shield.\n";
		return false;
	}
	
	ProtectionNode* new_skill_node = new ProtectionNode(protection_value);
	if (_head_node != nullptr) new_skill_node->_next = _head_node;
	_head_node = new_skill_node;
	_length++;	// to calculate the length
	return true;
}

void ProtectionLayer::pop() {
	if (_length == 0) {
		std::cout << "You have no shield to remove.\n";
		return;
	}
	_length--;

	ProtectionNode* temp = _head_node;
	_head_node = _head_node->_next;
	delete temp;
	return;
}

void ProtectionLayer::print() {
	ProtectionNode* temp = _head_node;
	std::cout << "\nProtection shield: \n";
	std::string status = "";
	for (int i = 1; temp != NULL; i++) {
		if (temp->_status == true) status = "active";
		if (temp->_status == false) status = "broken";

		std::cout << "Shield " << i << ": " << temp->_protection_value << " (" << status << ")\n";
		temp = temp->_next;
	}
	std::cout << '\n';
}

ProtectionNode& ProtectionLayer::Get_first_shield() {
	return *_head_node;
}

std::string ProtectionLayer::Get_ProtectionLayer() {
	ProtectionNode* temp = _head_node;
	std::string layer = "";

	for (int i = 1; temp != NULL; i++) {
		layer += (char)219u;
		layer += " ";
		temp = temp->_next;
	}
	return layer;
}

bool ProtectionLayer::isEmpty() {
	return (_head_node == NULL) ? true : false;
}
