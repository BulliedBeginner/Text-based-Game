#pragma once
#include <iostream>
enum SkillName {
	Fighting,
	Escape,
	Unlock
};

class SkillNode
{
public:
	SkillName _name;
	int _level;
	SkillNode* _next;

	SkillNode();
	SkillNode(SkillName name, int level);
	SkillNode(SkillName name, int level, SkillNode* link);
	~SkillNode();

	// // Getter
	// SkillName Get_Name();
	// int Get_Level();
	// SkillNode* Get_Next();

	// // Setter
	// void Set_Name(SkillName name);
	// void Set_Level(int level);
	// void Set_Next(SkillNode *next);

};

