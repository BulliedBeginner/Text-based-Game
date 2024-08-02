#include "SkillList.h"
SkillList::SkillList() {
	_length = 0;
	_head_node = nullptr;
}

SkillList::~SkillList() {}


void SkillList::push(SkillName skill_name, int skill_level) {
	SkillNode* new_skill_node = new SkillNode(skill_name, skill_level);

	if (_head_node != NULL) new_skill_node->_next =_head_node;
	_head_node = new_skill_node;
	_length++;	// to calculate the length
}

void SkillList::push_back(SkillName skill_name, int skill_level) {
	SkillNode* new_skill_node = new SkillNode(skill_name, skill_level);
	SkillNode* temp = _head_node;

	if (_head_node == NULL) {
		_head_node = new_skill_node;
	}
	else {
		temp = _head_node;
		while (temp->_next != NULL) {
			temp = temp->_next;
		}

		temp->_next =new_skill_node;
	}
	_length++;	// to calculate the length

}

void SkillList::prepend(SkillName skill_name, int skill_level, int position) {
	SkillNode* new_skill_node = new SkillNode(skill_name, skill_level);
	SkillNode* temp = _head_node;

	// If empty list, make current element as head
	if (_head_node == NULL) {
		_head_node = new_skill_node;
		return;
	}

	if (position == 1) {
		new_skill_node->_next = _head_node;
		_head_node = new_skill_node;
		return;
	}

	for (int i = 0; i < position - 2; i++) 
	{
		temp = temp->_next;
	}
	new_skill_node->_next =temp->_next;
	temp->_next =new_skill_node;
	
}

void SkillList::append(SkillName skill_name, int skill_level, int position) {
	SkillNode* new_skill_node = new SkillNode(skill_name, skill_level);
	SkillNode* temp = _head_node;

	// If empty list, make current element as head
	if (_head_node == NULL) {
		_head_node = new_skill_node;
		return;
	}

	if (position == 1) {
		new_skill_node->_next =_head_node;
		_head_node = new_skill_node;
		return;
	}

	for (int i = 0; i < position - 1; i++)
	{
		temp = temp->_next;
	}
	new_skill_node->_next = temp->_next;
	temp->_next = new_skill_node;
}

void SkillList::pop() {
	if (_length == 0) {
		std::cout << "The list is empty\n";
		return;
	}
	_length--;

	SkillNode* temp = _head_node;
	_head_node = _head_node->_next;
	delete temp;
	return;
}

void SkillList::pop_back() {
	if (_length == 0) {
		std::cout << "The list is empty\n";
		return;
	}
	_length--;

	// If there is only 1 element
	if (_head_node->_next == NULL) {
		_head_node = NULL;
		return;
	}

	SkillNode* temp = _head_node;
	while (temp->_next->_next != NULL) {
		temp = temp->_next;
	}

	SkillNode* last_node = temp->_next;
	temp->_next =NULL;
	delete last_node;
	
}

void SkillList::remove(int position) {
	// Prevent exceeded the list length
	if (_length < position) {
		std::cout << "Index out of range\n";
		return;
	}
	_length--;

	SkillNode* temp1 = _head_node;
	SkillNode* temp2 = NULL;

	if (_head_node == NULL) {
		std::cout << "List empty.\n";
		return;
	}

	// Deleting the head node
	if (position == 1) {

		// Update head
		_head_node = _head_node->_next;
		delete temp1;
		return;
	}

	// Traverse the list to find the node to be deleted.
	while (position-- > 1) {
		temp2 = temp1;
		temp1 = temp1->_next;
	}

	// Change the next pointer of the previous node.
	temp2->_next = temp1->_next;
	delete temp1;
}

void SkillList::read(int position) {
	// Prevent exceeded the list length
	if (_length < position) {
		std::cout << "Index out of range\n";
		return;
	}
	else 
	{
		if (position == 1) {
			std::cout << "Skill Name: " << _head_node->_name << " (" << _head_node->_level << ")\n";
			return;
		}

		SkillNode* temp = _head_node;
		for (int i = 0; i < position; i++) {
			temp = temp->_next;
		}
		std::cout << "Skill Name: " << temp->_name << " (" << temp->_level << ")\n";
		return;
	}
}

void SkillList::modifySkillName(SkillName skill_name, int position) {
	// Prevent exceeded the list length
	if (_length < position) {
		std::cout << "Index out of range\n";
		return;
	}

	// use temp instead head because this linked list cant return
	SkillNode* temp = _head_node;
	if (position == 1) {
		temp->_name = skill_name;
		return;
	}

	for (int i = 0; i < position - 1; i++) {
		temp = temp->_next;
	}
	temp->_name = skill_name;
}

void SkillList::modifySkillLevel(int skill_level, int position) {
	// Prevent exceeded the list length
	if (_length < position) {
		std::cout << "Index out of range\n";
		return;
	}

	SkillNode* temp = _head_node;
	if (position == 1) {
		temp->_level = skill_level;
		return;
	}

	for (int i = 0; i < position - 1; i++) {
		temp = (temp)->_next;
	}
	temp->_level = skill_level;
}

int SkillList::Get_Level(SkillName skill_name) {
	SkillNode* temp = _head_node;
	while (temp != NULL) {
		if (temp->_name == skill_name) {
			return temp->_level;
		};
		temp = temp->_next;
	}
	return temp->_level;
}

void SkillList::print() {
	SkillNode* temp = _head_node;
	std::cout << "\nSkill list: \n";
	std::string skill_name = "";
	while (temp != NULL) {
		if (temp->_name == Fighting) skill_name = "Fighting";
		if (temp->_name == Escape) skill_name = "Escape";
		if (temp->_name == Unlock) skill_name = "Unlock";

		std::cout << "Skill name: " << skill_name << " (" << temp->_level << ")\n";
		temp = temp->_next;
	}
	std::cout << '\n';
}

void SkillList::LevelUp() {
	SkillNode* temp = _head_node;
	while (temp != NULL) {
		temp->_level++;
		temp = temp->_next;
	}
}

void SkillList::line_print() {
	SkillNode* temp = _head_node;
	std::cout << "Skill list: ";
	std::string skill_name = "";
	while (temp != NULL) {
		if (temp->_name == Fighting) skill_name = "Fighting";
		if (temp->_name == Escape) skill_name = "Escape";
		if (temp->_name == Unlock) skill_name = "Unlock";

		std::cout << skill_name << " (" << temp->_level << ")    ";
		temp = temp->_next;
	}
	std::cout << "\n\n";
}