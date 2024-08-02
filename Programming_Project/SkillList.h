#pragma once
#include "SkillNode.h"

class SkillList
{
public:
	SkillNode* _head_node;
	int _length;
	void push_back(SkillName skill_name, int skill_level);

	SkillList();
	~SkillList();

	void append(SkillName skill_name, int skill_level, int position);
	void prepend(SkillName skill_name, int skill_level, int position);
	void push(SkillName skill_name, int skill_level);
	void pop();
	void pop_back();
	void remove(int position);
	void read(int position);
	void modifySkillName(SkillName skill_name, int position);
	void modifySkillLevel(int level, int position);
	int Get_Level(SkillName skill_name);
	void LevelUp();
	void print();
	void line_print();


};