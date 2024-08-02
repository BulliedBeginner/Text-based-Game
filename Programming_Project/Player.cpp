#include "Player.h"
void Player::call() {
	std::cout << "Calling from player.\n";
}

Player::~Player() {}

void Player::attack(Entity& entity) {
	int damage = _damage + _weapon_damage + _buff_damage;
	entity._hp.current -= damage;
}

bool Player::isAlive() {
	if (_hp.current <= 0) return false;
	return true;
}

void Player::pickItem(Item *item) {
	 _inventory.addItem(item);
	 std::cout << "You have picked up " << item->Get_Name() << "\n";
}

void Player::showInventory() {
	_inventory.print();
}

void Player::line_inventory() {
	_inventory.linePrint();
}


void Player::moveNextStage() {
	
}

bool Player::buy(Item &item) {
	if ((_gold - item._price) < 0) {
		std::cout << "Not enough gold\n";
		return false;
	}

	_gold -= item._price;
	_inventory.addItem(&item);
	std::cout << "You have bought " << item.Get_Name() << "\n";
	std::cout << "You now have $" << _gold << " left.\n";
	return true;
}

void Player::checkBuff() {
	BuffType buffType;
	for (int i = 0; i < _buff._length; i++) {
		buffType = _buff.Get_Buff(i);

		if (buffType == Heal) {
			_hp.current += 10;
			if (_hp.current > _hp.max) {
				_hp.current = _hp.max;
			}
		}

		else if (buffType == DoubleHeal) {
			_hp.current += 20;
			if (_hp.current > _hp.max) {
				_hp.current = _hp.max;
			}
		}

		else if (buffType == DoubleDamage) {
			_buff_damage = (_damage * 2) - _damage;
		}

		else if (buffType == TripleDamage) {
			_buff_damage = (_damage * 3) - _damage;
		}

	}
}

bool Player::buff(BuffType buff) {
	int mana_cost = 0;
	if (buff == Heal) mana_cost = 20;
	if (buff == DoubleDamage) mana_cost = 40;
	if (buff == DoubleHeal) mana_cost = 40;
	if (buff == TripleDamage) mana_cost = 80;
	if (mana_cost > _mp) {
		std::cout << "You have no enough mana.\n";
		return false;
	}
	_mp -= mana_cost;
	_buff.enqueue(buff);
	return true;
}

void Player::debuff() {
	_buff.dequeue();
}

void Player::status() {

}

void Player::line_status() {
	int damage = _damage + _weapon_damage + _buff_damage;
	std::cout
		<< "HP: " << _hp.current
		<< "     MP: " << _mp
		<< "     Gold: " << _gold
		<< "     Damage: " << damage
		<< "     Armor: " << _armor_reduction
		<< "     Shield: " << _protection.Get_ProtectionLayer()
		<< "     Buff: " << _buff.Get_StringBuff()
		<< "\n\n";
}

void Player::checkEquipedItem() {
	bool first = true;
	bool second = true;
	for (auto& x : _inventory._array) {
		if (x->_isEquip && x->_itemType == weapon && first) {
			_weapon_damage = x->Get_Damage();
			first = false;
		}

		if (x->_isEquip && x->_itemType == armor && second) {
			_armor_reduction = x->Get_Damage();
			second = false;
		}
	}
}

// // Getter
// int Player::Get_Level() { return _level; }
// int Player::Get_Gold() { return _gold; }
// Inventory* Player::Get_Inventory() { return _inventory; }

// // Setter
// void Player::Set_Level(int level) { _level = level; }
// void Player::Set_Gold(int gold) { _gold = gold; }