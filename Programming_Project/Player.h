#pragma once
#include "Entity.h"
#include "Inventory.h"
#include "SkillList.h"
#include "Buff.h"
#include "ProtectionLayer.h"

class Player : public Entity
{
protected:
	Player() {
		_name = "Steve";
		_damage = 10;
		_hp.max = 100;
		_hp.current = 100;
		_mp = 100;
		_gold = 100;
		_armor_reduction = 0;
		_weapon_damage = 0;
		_buff_damage = 0;
		_buff = Buff();
	}

public:
	void call();

	static Player& get_instance() {
		static Player player;
		return player;
	}

	Inventory _inventory;
	int _gold;
	Buff _buff;
	ProtectionLayer _protection;
	SkillList _skill_list;
	int _armor_reduction;
	int _weapon_damage;
	int _buff_damage;

	~Player();

	void attack(Entity &entity);
	bool isAlive();
	void pickItem(Item *item);
	void showInventory();
	void moveNextStage();
	bool buy(Item &item);
	void checkBuff();
	bool buff(BuffType buff);
	void debuff();
	void status();
	void line_status();
	void line_inventory();
	void checkEquipedItem();

	// // Getter
	// int Get_Level();
	// int Get_Gold();
	// Inventory* Get_Inventory();

	// // Setter
	// void Set_Level(int level);
	// void Set_Gold(int gold);
};

