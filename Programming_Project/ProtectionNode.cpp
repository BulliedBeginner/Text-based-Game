#include "ProtectionNode.h"
ProtectionNode::ProtectionNode() {
	_protection_value = 30;
	_next = nullptr;
	_status = true;
}

ProtectionNode::ProtectionNode(int protection_value) {
	_protection_value = protection_value;
	_next = nullptr;
	_status = true;
}

ProtectionNode::~ProtectionNode() { }

void ProtectionNode::broke() {
	_status = false;
}