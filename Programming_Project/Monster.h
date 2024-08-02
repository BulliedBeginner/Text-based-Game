#pragma once
#include "Entity.h"
enum MonsterType {
	Zombie,
	Vampire,
	Giant,
	Boss
};

class Monster : public Entity
{
public:
	int _gold_drop;
	MonsterType _type;
	Monster();
	Monster(MonsterType type);
	~Monster();
	void call();
};

