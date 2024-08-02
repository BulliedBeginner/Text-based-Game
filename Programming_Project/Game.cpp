#include "Game.h"
Game::Game() {
	// all the stage are initialized, not randomly generated
	_stage_list.push_back(Zombie);
	_stage_list.push_back(Zombie);
	_stage_list.push_back(Vampire);
	_stage_list.push_back(Giant);
	_stage_list.push_back(Boss);

	_hasEnd = false;
	_monster_name = _stage_list.Get_Stage(stageNumber)._monster._name;
	_player._protection.push(20);

	_player._skill_list.push(Fighting, 1);
	_player._skill_list.push(Unlock, 1);
	_player._skill_list.push(Escape, 1);
}
Game::~Game() {}

void Game::initialise() {
	std::string input;
	std::cout << "Hello adventurer what is your name?\n";
	std::cout << "Enter your character name:  ";
	getline(std::cin, input);
	_player._name = input;
	std::cout << "Hello " << _player._name << ", Welcome to Dungeon Adventure.\n";
}

void Game::run() {
	// check if player did equip item
	_player.checkEquipedItem();

	// check buff
	if (!_player._buff.isEmpty()) {
		_player.checkBuff();
	}

	_player.line_status();
	_player._skill_list.line_print();
	_player.line_inventory();
	std::cout << "\n========================================================================================================================";

	std::cout << "\nCurent stage: " << stageNumber << "\n\n";
	std::cout << "Monster: " << _monster_name;
	std::cout << "   HP: " << _stage_list.Get_Stage(stageNumber)._monster._hp.current;
	std::cout << "   Damage: " << _stage_list.Get_Stage(stageNumber)._monster._damage << "\n\n";

	std::cout << "Available command:\n"
		<< "   attack\n"
		<< "   buff - Heal, DoubleHeal, DoubleDamage, TripleDamage\n"
		<< "   escape - back to first room\n"
		<< "   shop - enter shop\n"
		<< "   shield - recover shield with strengthness value (mana cost = value)\n"
		<< "   next - only if you have cleared the current room\n"
		<< "   back - back to previous room\n"
		<< "   exit - exit game\n\n";

	begin:
	std::string command = command_input();
	std::string* parsed_command = parseCommandLine(command);
	if (validCommand(parsed_command)) {
		if (!execute_command(parsed_command)) {
			goto begin;
		}
	}
	else {
		goto begin;
	}

	// if boss is defeated
	if (_stage_list.Get_Stage(stageNumber)._monster._hp.current <= 0 && _stage_list.Get_Stage(stageNumber)._monster._type == Boss) {
		end();
		return;
	}

	// if monster has dead
	if (_stage_list.Get_Stage(stageNumber)._monster._hp.current <= 0 && _stage_list.Get_Stage(stageNumber)._isAlive) {
		std::cout << "The monster has dropped $" << _stage_list.Get_Stage(stageNumber)._monster._gold_drop << "\n";
		std::cout << "Monster defeated. You have entered next stage.\n";
		_player._gold += _stage_list.Get_Stage(stageNumber)._monster._gold_drop;
		_stage_list.Get_Stage(stageNumber)._isAlive = false;

		// skill lvl up
		_player._skill_list.LevelUp();

		stageNumber++;
		_monster_name = _stage_list.Get_Stage(stageNumber)._monster._name;
		system("Pause");
		system("CLS");
	}

	// if monster still alive
	else if (_stage_list.Get_Stage(stageNumber)._monster._hp.current > 0 && _stage_list.Get_Stage(stageNumber)._isAlive == true) {
		MonsterAttack();	
	}

	system("Pause");
	system("CLS");
}

void Game::MonsterAttack() {
	// if has protection
	if (!_player._protection.isEmpty()) {
		int monster_damage = _stage_list.Get_Stage(stageNumber)._monster._damage;

		_player._protection.Get_first_shield()._protection_value -= monster_damage;
		std::cout << "Your shield has blocked " << monster_damage << " damage.\n";

		if (_player._protection.Get_first_shield()._protection_value <= 0) {
			_player._protection.pop();
			std::cout << "Your shield has broken\n";
		}
		return;
	}

	else {
		int monster_damage = _stage_list.Get_Stage(stageNumber)._monster._damage - _player._armor_reduction;
		_player._hp.current -= monster_damage;
		std::cout << _monster_name << " has attacked you and dealt " << monster_damage << " damage to you.\n";
	}

	player_alive();
}

void Game::end() {
	std::cout << "Game ended, hope you have fun.\n";
	_hasEnd = true;
}

std::string Game::command_input() {
	std::string command;
	std::cout << "What you gonna do: ";
	getline(std::cin, command);
	return command;
}

bool Game::execute_command(std::string* command) {

	if (command[0] == "attack") {
		if (_stage_list.Get_Stage(stageNumber)._monster._hp.current <= 0) {
			std::cout << "There is no monster in this room.\n";
			return false;
		}
		_player.attack(_stage_list.Get_Stage(stageNumber)._monster);
		std::cout << "You have attacked " << _monster_name << " for " << _player._damage + _player._weapon_damage << " damage.\n";
		return true;
	}

	else if (command[0] == "buff") {
		BuffType buff = convert_buff(command[1]);
		if (_player.buff(buff)) {
			return true;
		}
		return false;
	}

	else if (command[0] == "escape") {
		if (_stage_list.Get_Stage(stageNumber)._monster._type == Giant &&
			_stage_list.Get_Stage(stageNumber)._monster._hp.current > 0 &&
			_stage_list.Get_Stage(stageNumber)._isAlive == true &&
			_player._skill_list.Get_Level(Escape) < 5
			) {
			std::cout << "Can't escape, skill escape level 5 required\n";
			return false;
		}

		stageNumber = 1;
		_monster_name = _stage_list.Get_Stage(stageNumber)._monster._name;
		std::cout << "Escape successful\n";
		return true;
	}

	else if (command[0] == "shop") {
		if (_stage_list.Get_Stage(stageNumber)._monster._hp.current > 0) {
			std::cout << "You can't buy item when you are in battle.\n";
			return false;
		}

		std::string choice = "";
		std::cout
			<< "Menu: \n"
			<< "1. Iron Sword: $30\n"
			<< "2. Diamond Sword: $40\n"
			<< "3. Iron Armor: $30\n"
			<< "4. Diamond Armor: $60\n"
			<< "5. Exit shop\n\n";

		begin:
		std::cout << "Enter the number: ";
		std::cin >> choice;
		if (choice == "1") {
			Weapon* w = new Weapon(IronSword, true);
			Item* i = w;
			_player.buy(*i);
			// check item
			_player.checkEquipedItem();
			goto begin;
		}

		else if (choice == "2") {
			Weapon* w = new Weapon(DiamondSword, true);
			Item* i = w;
			_player.buy(*i);
			// check item
			_player.checkEquipedItem();
			goto begin;
		}

		else if (choice == "3") {
			Armor* a = new Armor(IronArmor, true);
			Item* i = a;
			_player.buy(*i);
			// check item
			_player.checkEquipedItem();
			goto begin;
		}

		else if (choice == "4") {
			Armor* a = new Armor(DiamondArmor, true);
			Item* i = a;
			_player.buy(*i);
			// check item
			_player.checkEquipedItem();
			goto begin;
		}

		else if (choice == "5") {
			return false;
		}

		else {
			goto begin;
		}

		return false;
	}

	else if (command[0] == "shield") {
		int value = std::stoi(command[1]);
		if (_player._mp >= value) {
			if (!_player._protection.push(value)) {
				return false;
			}
			_player._mp -= value;
		}
		return false;
	}

	else if (command[0] == "next") {
		if (_stage_list.Get_Stage(stageNumber)._monster._hp.current > 0 && _stage_list.Get_Stage(stageNumber)._isAlive == true) {
			std::cout << "Cannot move to next room, there is monster in this room.\n";
			return false;
		}
		stageNumber++;
		_monster_name = _stage_list.Get_Stage(stageNumber)._monster._name;
		std::cout << "You have moved to next room.\n";
		return true;
	}

	else if (command[0] == "back") {
		if (_stage_list.Get_Stage(stageNumber)._monster._hp.current > 0 && _stage_list.Get_Stage(stageNumber)._isAlive == true) {
			std::cout << "Can't return back when there is monster.\n";
			return false;
		}
		stageNumber--;
		_monster_name = _stage_list.Get_Stage(stageNumber)._monster._name;
		std::cout << "You have returned back to previous room.\n";
		return true;
	}

	else if (command[0] == "exit") {
		end();
		return true;
	}

	return false;
}

void Game::player_alive() {
	if (!_player.isAlive()) {
		end();
	}
}

bool Game::validCommand(std::string* command) {
	std::string command_list[] = { "attack", "buff", "restore", "escape", "shop", "shield", "next", "back", "exit"};
	std::string skill_name[] = { "Fighting", "Escape", "Unlock" };
	std::string buff_name[] = { "Heal", "DoubleHeal", "DoubleDamage", "TripleDamage"};


	if (!(std::count(std::begin(command_list), std::end(command_list), *command) > 0)) {
		std::cout << "Invalid Command: " << *command << "\n";
		return false;
	}

	if (command[0] == "buff") {
		// check if buff exist (first parameter)
		if (!(std::count(std::begin(buff_name), std::end(buff_name), command[1]) > 0)) {
			std::cout << "Unknown buff: " << command[1] << "\n";
			return false;
		}
	}

	if (command[0] == "shield") {
		// check shield strengthness (first parameter)
		if (!isNumber(command[1])) {
			std::cout << "Invalid number: " << command[1] << "\n";
			return false;
		}
	}
	return true;
}

std::string* Game::parseCommandLine(std::string command) {
	int i = 0;
	std::string word = "";
	static std::string parsed_command[4];

	for (auto& x : command) {
		if (x == ' ') {
			parsed_command[i] = word;
			i++;
			word = "";
		}
		else {
			word = word + x;
		}
	}
	// for the last word
	parsed_command[i++] = word;

	return parsed_command;
}

BuffType Game::convert_buff(std::string buff_name) {
	if (buff_name == "Heal") return Heal;
	else if (buff_name == "DoubleHeal") return DoubleHeal;
	else if (buff_name == "DoubleDamage") return DoubleDamage;
	else if (buff_name == "TripleDamage") return TripleDamage;
	else { return Heal; }
}

bool Game::isNumber(const std::string& s)
{
	for (char const& ch : s) {
		if (std::isdigit(ch) == 0)
			return false;
	}
	return true;
}