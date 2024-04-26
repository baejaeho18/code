#include "character.h"

Character::Character() {
	prev_attack = attack = 10;
	prev_defense =defense = 2;
	gold = 0;
	prev_level = level = 1;
	prev_curr_hp = prev_max_hp = curr_hp = max_hp = 100;
	prev_curr_mp = prev_max_mp = curr_mp = max_mp = 20;
	prev_max_exp = max_exp = 100;
	prev_curr_exp = curr_exp = 0;
}

//Character::~Character() {
//	std::cout << std::endl;
//	std::cout << "You died..." << std::endl;
//}

int Character::getGold() const { return gold; }
//int Character::getLevel() const { return level; }
//int Character::getAttack() const { return attack; }
//int Character::getDefense() const { return defense; }
//int Character::getMaxHP() const { return max_hp; }
//int Character::getCurrHP() const { return curr_hp; }
//int Character::getMaxMP() const { return max_mp; }
//int Character::getCurrMP() const { return curr_mp; }
//int Character::getMaxExp() const { return max_exp; }
//int Character::getCurrExp() const { return curr_exp; }
//void Character::setCurrHP(int value) { curr_hp = value; }

void Character::level_up_if_possible() {	// after fighting
	prev_level = level;
	prev_attack = attack;
	prev_defense = defense;
	prev_curr_exp = curr_exp;
	prev_max_exp = max_exp;
	prev_curr_hp = curr_hp;
	prev_max_hp = max_hp;
	prev_curr_mp = curr_mp;
	prev_max_mp = max_mp;
	while (max_exp < curr_exp) {
		level += 1;
		attack += 3;
		defense += 1;
		curr_hp = max_hp += 50;
		curr_mp = max_mp += 10;
		curr_exp -= max_exp;
		max_exp = level * 100;
	}
	if (prev_level != level) {
		std::cout << "Level up!" << std::endl;
		std::cout << "=======================================" << std::endl;
		std::cout << "Character status" << std::endl;
		show_character_status_changed();
		std::cout << "=======================================" << std::endl;
	}
}

void Character::level_up_if_possible(int prev_curr_exp_) {	// after shopping
	prev_level = level;
	prev_attack = attack;
	prev_defense = defense;
	prev_curr_exp = prev_curr_exp_;
	prev_max_exp = max_exp;
	prev_curr_hp = curr_hp;
	prev_max_hp = max_hp;
	prev_curr_mp = curr_mp;
	prev_max_mp = max_mp;
	while (max_exp < curr_exp) {
		level += 1;
		attack += 3;
		defense += 1;
		curr_hp = max_hp += 50;
		curr_mp = max_mp += 10;
		curr_exp -= max_exp;
		max_exp = level * 100;
	}
}

bool Character::is_alive() {
	if (0 < curr_hp)
		return true;
	return false;
}

void Character::attack_basic(Monster& enemy){
	int damage = enemy.injured(attack);
	std::cout << "You hit the monster with " << damage << " damage!" << std::endl;
}

void Character::attack_skill(Monster& enemy){
	if (curr_mp < 15) {
		std::cout << "Not enough MP..." << std::endl;
		return;
	}
	curr_mp -= 15;
	int damage = enemy.injured_skill(attack);
	std::cout << "You hit the monster with " << damage << " damage!" << std::endl;
}

void Character::attack_fire(Monster& enemy){
	if (curr_mp < 15) {
		std::cout << "Not enough MP..." << std::endl;
		return;
	}
	curr_mp -= 15;
	int damage = enemy.injured_fire(attack);
	std::cout << "You hit the monster with " << damage << " damage!" << std::endl;
}

void Character::attack_grass(Monster& enemy){
	if (curr_mp < 15) {
		std::cout << "Not enough MP..." << std::endl;
		return;
	}
	curr_mp -= 15;
	int damage = enemy.injured_grass(attack);
	std::cout << "You hit the monster with " << damage << " damage!" << std::endl;
}

void Character::attack_water(Monster& enemy){
	if (curr_mp < 15) {
		std::cout << "Not enough MP..." << std::endl;
		return;
	}
	curr_mp -= 15;
	int damage = enemy.injured_water(attack);
	std::cout << "You hit the monster with " << damage << " damage!" << std::endl;
}

int Character::injured(int damage) {
	damage -= defense;
	curr_hp -= (damage < 0) ? 0 : damage;
	return damage;
}

void Character::show_character_status() {
	using namespace std;
	cout << "Level: " << level << endl;
	cout << "Attack: " << attack << endl;
	cout << "Defense: " << defense << endl;
	cout << "Gold: " << gold << endl;
	cout << "HP: " << curr_hp << " / " << max_hp << endl;
	cout << "MP: " << curr_mp << " / " << max_mp << endl;
	cout << "EXP: " << curr_exp << " / " << max_exp << endl;
}

void Character::show_character_status_changed() {
	std::cout << "Level: ";
	if (level != prev_level)
		std::cout << prev_level << " => ";
	std::cout << level << std::endl;
	std::cout << "Attack: ";
	if (attack != prev_attack)
		std::cout << prev_attack << " => ";
	std::cout << attack << std::endl;
	std::cout << "Defense: ";
	if (defense != prev_defense)
		std::cout << prev_defense << " => ";
	std::cout << defense << std::endl;
	std::cout << "HP: ";
	if (curr_hp != prev_curr_hp)
		std::cout << prev_curr_hp << " / " << max_hp << " => ";		// print previous hp
	std::cout << curr_hp << " / " << max_hp << std::endl;
	std::cout << "MP: ";
	if (prev_curr_mp != curr_mp)
		std::cout << prev_curr_mp << " / " << max_mp << " => ";		// print previous mp
	std::cout << curr_mp << " / " << max_mp << std::endl;
	std::cout << "EXP: ";
	if (prev_curr_exp != curr_exp || prev_max_exp != max_exp)
		std::cout << prev_curr_exp << " / " << max_exp << " => ";	// print previous exp
	std::cout << curr_exp << " / " << max_exp << std::endl;
}

bool Character::purchasable(int cost) {
	return (cost <= gold);
}

void Character::purchase(int opt, Item item) {
	if (opt == ATK_BUF) {
		prev_attack = attack;
		attack += item.buf;
	}
	else if (opt == DEF_BUF) {
		prev_defense = defense;
		defense += item.buf;
	}
	else if (opt == EXP_BUF) {
		prev_curr_exp = curr_exp;
		curr_exp += item.buf;
		// level up
		level_up_if_possible(prev_curr_exp);		// Todo: should not show levelup message and keep prev_curr_exp
	}
	else if (opt == HP_BUF) {
		prev_curr_hp = curr_hp;
		curr_hp = max_hp;
	}
	else if (opt == MP_BUF) {
		prev_curr_mp = curr_mp;
		curr_mp = max_mp;
	}
	// else wouldn't be happen
	gold -= item.cost;
}

void Character::percentage_damage(double percentage) {
	curr_hp = curr_hp * (1 - percentage) + ROUND;
}

void Character::percentage_restore(double percentage) {
	curr_hp += (max_hp - curr_hp) * percentage + ROUND;
}

void Character::looting_gold(int gold_) {
	gold += gold_;
}

void Character::looting_exp(int exp_) {
	curr_exp += exp_;
}