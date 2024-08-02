#pragma once
#include "StageNode.h"
class StageList
{
public:
	StageNode* _head_node;
	StageNode* _tail_node;
	int _length;
	void push_back(Monster monster);

	StageList();
	~StageList();

	StageNode& Get_Stage(int position);
	void append(Monster monster, int position);
	void prepend(Monster monster, int position);
	void push(Monster monster);
	void pop();
	void pop_back();
	void deleteNode(StageNode* del);
	void remove(int position);
	void read(int position);
	void modifyStageMonster(Monster monster, int position);
	void print();
};

