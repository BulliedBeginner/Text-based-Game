#include "StageNode.h"
StageNode::StageNode() {
	_next = nullptr;
	_prev = nullptr;
	_monster = Monster(Zombie);
	_isAlive = true;
}

StageNode::StageNode(Monster monster) {
	_next = nullptr;
	_prev = nullptr;
	_monster = monster;
	_isAlive = true;
}

StageNode::~StageNode() { }