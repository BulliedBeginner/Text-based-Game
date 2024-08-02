#pragma once
#include <iostream>
#include "ProtectionNode.h"
class ProtectionLayer
{
public:
	ProtectionNode* _head_node;
	int _length;
	int _capacity;

	ProtectionLayer();
	~ProtectionLayer();

	ProtectionNode& Get_first_shield();
	bool push(int protection_value);
	void pop();
	void print();
	bool isEmpty();
	std::string Get_ProtectionLayer();
};