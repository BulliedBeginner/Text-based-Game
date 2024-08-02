#pragma once
#include <iostream>
struct HP {
	int max;
	int current;
};

class Entity
{
public:
	std::string _name;
	HP _hp;
	int _mp;
	int _damage;

	Entity();
	Entity(std::string name, int max_hp, int mp, int damage);
	~Entity();
	virtual void attack(Entity& entity);
	virtual void call();
};

