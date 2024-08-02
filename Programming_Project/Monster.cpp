#include "Monster.h"

void Monster::call() {
	std::cout << "Calling from monster.\n";
}

Monster::Monster() {
	_name = "Zombie";
	_type = Zombie;
	_damage = 10;
	_hp.max = 40;
	_hp.current = 40;
	_gold_drop = 10;
}
Monster::Monster(MonsterType type) {
	_type = type;

	if (type == Zombie) {
		_name = "Zombie";
		_damage = 10;
		_hp.max = 20;
		_hp.current = 20;
		_gold_drop = 10;
	}

	if (type == Vampire) {
		_name = "Vampire";
		_damage = 20;
		_hp.max = 40;
		_hp.current = 40;
		_gold_drop = 20;
	}
	
	if (type == Giant) {
		_name = "Giant";
		_damage = 30;
		_hp.max = 60;
		_hp.current = 60;
		_gold_drop = 30;
	}

	if (type == Boss) {
		_name = "Boss";
		_damage = 50;
		_hp.max = 100;
		_hp.current = 100;
		_gold_drop = 100;
	}
}
Monster::~Monster() {}