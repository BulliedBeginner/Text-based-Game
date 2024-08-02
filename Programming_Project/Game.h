#pragma once
#include <algorithm>
#include <string>
#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "StageList.h"

class Game
{
public:
	bool _hasEnd;
	StageList _stage_list;
	Player _player = Player::get_instance();
	int stageNumber = 1;
	std::string _monster_name = "";

	Game();
	~Game();

	void initialise();
	void run();
	void end();
	std::string command_input();
	bool execute_command(std::string* command);
	void player_alive();
	void MonsterAttack();
	bool validCommand(std::string* command);
	std::string* parseCommandLine(std::string command);
	BuffType convert_buff(std::string buff_name);
	bool isNumber(const std::string& s);

};

