#include "BuffNode.h"
BuffNode::BuffNode() {
	_buffType = Blank;
	_next = nullptr;
	_mana_cost = 0;
}

BuffNode::BuffNode(BuffType buffType) {
	_buffType = buffType;
	_next = nullptr;
	_mana_cost = 20;
	if (buffType == Heal) {
		_mana_cost = 20;
	}
	if (buffType == DoubleDamage) {
		_mana_cost = 40;
	}
	if (buffType == DoubleHeal) {
		_mana_cost = 40;
	}
	if (buffType == TripleDamage) {
		_mana_cost = 80;
	}
}

BuffNode::~BuffNode() {

}