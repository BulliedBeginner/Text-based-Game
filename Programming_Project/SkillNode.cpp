#include "SkillNode.h"
SkillNode::SkillNode() {
	_name = Fighting;
	_level = 1;
	_next = nullptr;
}
SkillNode::SkillNode(SkillName name, int level) {
	_name = name;
	_level = level;
	_next = nullptr;
}
SkillNode::SkillNode(SkillName name, int level, SkillNode* link) {
	_name = name;
	_level = level;
	_next = link;
}
SkillNode::~SkillNode() {}



// // Getter
// SkillName SkillNode::Get_Name() { return _name; }
// int SkillNode::Get_Level() { return _level;}
// SkillNode* SkillNode::Get_Next() { return _next; }

// // Setter
// void SkillNode::Set_Name(SkillName name) { _name = name;}
// void SkillNode::Set_Level(int level) { _level = level;}
// void SkillNode::Set_Next(SkillNode* next) { _next = next; }
