#pragma once
#include "Monster.h"
class StageNode
{
public:
	StageNode* _next;
	StageNode* _prev;
	Monster _monster;
	bool _isAlive;

	StageNode();
	StageNode(Monster monster);
	~StageNode();

};

