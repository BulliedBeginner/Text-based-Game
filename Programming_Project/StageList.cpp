#include "StageList.h"
StageList::StageList() {
	_length = 0;
	_head_node = nullptr;
	_tail_node = nullptr;
}

StageList::~StageList() {}

StageNode& StageList::Get_Stage(int position) {
	StageNode* temp = _head_node;
	if (_length < position) {
		std::cout << "Invalid stage number1\n";
		return *temp;
	}

	if (position == 1) {
		return *temp;
	}

	for (int i = 0; i < position - 1; i++)
	{
		temp = temp->_next;
	}
	return *temp;
}


void StageList::append(Monster monster, int position) {
	StageNode* newNode = new StageNode(monster);
	StageNode* temp = _head_node;
	_length++;

	if (_head_node == NULL)
	{
		_head_node = newNode;
		return;
	}

	for (int i = 0; i < position - 1; i++)
	{
		temp = temp->_next;
		if (temp == NULL)
		{
			std::cout << "Cannot insert here" << "\n";
			return;
		}
	}
	newNode->_next = temp->_next;
	newNode->_prev = temp;
	temp->_next = newNode;
	temp->_next->_prev = newNode;
}

void StageList::prepend(Monster monster, int position) {
	StageNode* newNode= new StageNode(monster);
	StageNode *temp = _head_node;
	_length++;

	if (_head_node == NULL)
	{
		_head_node = newNode;
		return;
	}

	if (position == 1) {
		newNode->_next = _head_node;
		_head_node->_prev = newNode;
		_head_node = newNode;
		return;
	}
	
	for (int i = 0; i < position - 2 && temp != NULL; i++) {
		temp = temp->_next;
	}
	newNode->_next = temp->_next;
	newNode->_prev = temp;
	if (temp->_next != NULL)
	{
		temp->_next->_prev = newNode;
	}
	temp->_next = newNode;
}

void StageList::push(Monster monster) {
	StageNode* newNode = new StageNode(monster);
	newNode->_next = _head_node;
	_length++;

	if (_head_node != NULL)
		_head_node->_prev = newNode;
	_head_node = newNode;
}

void StageList::push_back(Monster monster) {
	StageNode* newNode = new StageNode(monster);
	StageNode* temp = _head_node;
	_length++;

	if (_head_node == NULL) {
		newNode->_prev = NULL;
		_head_node = newNode;
		return;
	}

	while (temp->_next != NULL) {
		temp = temp->_next;
	}

	temp->_next = newNode;
	newNode->_prev = temp;
}

void StageList::pop() {
	if (_length == 0) {
		std::cout << "The list is empty\n";
		return;
	}
	_length--;

	if (_head_node != NULL) {
		StageNode* temp = _head_node;
		_head_node = _head_node->_next;
		free(temp);
		if (_head_node != NULL)
			_head_node->_prev = NULL;
	}
}

void StageList::pop_back() {
	if (_head_node->_next == NULL) {
		_head_node = NULL;
	}
	else {
		StageNode* temp = _head_node;
		while (temp->_next->_next != NULL)
			temp = temp->_next;

		StageNode* lastNode = temp->_next;
		temp->_next = NULL;
		delete lastNode;
		_length--;
	}
}

void StageList::deleteNode(StageNode* del) {
	if (_head_node == NULL || del == NULL) {
		return;
	}
	
	if (_head_node == del) {
		_head_node = del->_next;
	}
	
	if (del->_next != NULL) {
		del->_next->_prev = del->_prev;
	}
	
	if (del->_prev != NULL) {
		del->_prev->_next = del->_next;
	}
	delete del;
}

void StageList::remove(int position) {
	if (_length < position) {
		std::cout << "Invalid stage number\n";
		return;
	}

	if (_head_node == NULL || position <= 0) {
		return;
	}
	StageNode* current = _head_node;
	for (int i = 1; current != NULL && i < position; i++) {
		current = current->_next;
	}
	if (current == NULL) {
		return;
	}
	deleteNode(current);
	_length--;
}

void StageList::read(int position) {
	if (_length < position) {
		std::cout << "Invalid stage number\n";
		return;
	}
	else
	{
		if (position == 1) {
			std::string monster = "";
			if (_head_node->_monster._type == Zombie) monster = "Zombie";
			if (_head_node->_monster._type == Vampire) monster = "Vampire";
			if (_head_node->_monster._type == Giant) monster = "Giant";
			std::cout << "Stage: 1" << " Monster: " << monster << "\n";
			return;
		}

		int i = 1;
		StageNode* temp = _head_node;
		for (; i < position; i++) {
			temp = temp->_next;
		}
		std::string monster = "";
		if (temp->_monster._type == Zombie) monster = "Zombie";
		if (temp->_monster._type == Vampire) monster = "Vampire";
		if (temp->_monster._type == Giant) monster = "Giant";
		std::cout << "Stage: " << i << " Monster: " << monster << "\n";
		return;
	}
}

void StageList::modifyStageMonster(Monster monster, int position) {
	if (_length < position) {
		std::cout << "Invalid stage number\n";
		return;
	}

	StageNode* temp = _head_node;
	if (position == 1) {
		temp->_monster = monster;
		return;
	}

	for (int i = 0; i < position - 1; i++) {
		temp = temp->_next;
	}
	temp->_monster = monster;
}

void StageList::print() {
	int i = 0;
	StageNode* temp = _head_node;
	std::cout << "Stage list: \n";
	while (temp != NULL) {
		std::cout << "Stage " << ++i << ": " << "Monster: " << temp->_monster._name << "\n";
		temp = temp->_next;
	}
	std::cout << '\n';
}

