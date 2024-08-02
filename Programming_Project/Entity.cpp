#include "Entity.h"
Entity::Entity() {
	_name = "Unknown Entity";
	_hp.max = 100;
	_hp.current = 100;
	_mp = 100;
	_damage = 10;
}
Entity::Entity(std::string name, int max_hp, int mp, int damage) : _name(name), _mp(max_hp), _damage(damage) {
	_hp.max = max_hp;
	_hp.current = max_hp; // full health by default
}
Entity::~Entity() { }

void Entity::attack(Entity &entity) {
	entity._hp.current -= _damage;
}

void Entity::call() {
	std::cout << "Calling from entity\n";
}


// // Getter
// int Entity::Get_ID() { return _ID; }
// std::string Entity::Get_Name() {return _name;}
// int Entity::Get_MaxHP() {return _hp.max; }
// int Entity::Get_CurrentHP() {return _hp.current; }
// int Entity::Get_MP() {return _mp; }
// int Entity::Get_Damage() {return _damage; }
// Buff Entity::Get_buffLayer() { return _buffLayer; }

// // Setter
// void Entity::Set_ID(int id) {_ID = id; }
// void Entity::Set_Name(std::string Name) {_name = Name; }
// void Entity::Set_MaxHP(int max_hp) { _hp.max = max_hp; }
// void Entity::Set_CurrentHP(int current_hp) { _hp.current = current_hp; }
// void Entity::Set_MP(int MP) {_mp = MP; }
// void Entity::Set_Damage(int Damage) {_damage = Damage; }
// void Entity::Set_buffLayer(Buff buff) { _buffLayer = buff; }