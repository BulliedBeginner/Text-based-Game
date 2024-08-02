#pragma once
class ProtectionNode
{
public:
	int _protection_value;
	ProtectionNode* _next;
	bool _status;

	ProtectionNode();
	ProtectionNode(int protection_value);
	~ProtectionNode();

	void broke();
};

