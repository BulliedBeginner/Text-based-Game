#pragma once
enum BuffType {
	Blank,
	Heal,
	DoubleDamage,
	DoubleHeal,
	TripleDamage
};

class BuffNode
{
public:
	BuffType _buffType;
	BuffNode* _next;
	int _mana_cost;

	BuffNode();
	BuffNode(BuffType buffType);
	~BuffNode();

};

