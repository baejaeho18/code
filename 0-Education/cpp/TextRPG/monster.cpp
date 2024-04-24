#include "monster.h"

// Monster
Monster::Monster(int difficulty) {
	max_hp = 50 + (difficulty * 5);
	curr_hp = max_hp;
	attack = 5 + difficulty * 2;
	defense = 2 + difficulty / 2.0 + ROUND;
	reward = 100 + difficulty * 10;
	attribute = rand() % 4;
}

// Boss
Monster::Monster(int attack_, int defense_, int hp_) 
	: max_hp(hp_), curr_hp(hp_), attack(attack_), defense(defense_)
{
	reward = -1;
	attribute = rand() % 4;
}

int Monster::get_reward() {
	return reward;
}

void Monster::attack_basic(Character& gamer) {
	int damage = gamer.injured(attack);
	std::cout << "Monster hit you with " << damage << " damage!" << std::endl;
}

int Monster::injured(int damage) {
	damage -= defense;
	curr_hp -= damage;
	return damage;
}

int Monster::injured_skill(int damage) {
	damage = (double)damage * 1.5 + ROUND;
	return injured(damage);
}

int Monster::injured_fire(int damage) {
	if (attribute == GRASS)
		damage *= 2;
	return injured(damage);
}

int Monster::injured_grass(int damage) {
	if (attribute == WATER)
		damage *= 2;
	return injured(damage);
}

int Monster::injured_water(int damage) {
	if (attribute == FIRE)
		damage *= 2;
	return injured(damage);
}

bool Monster::is_alive() {
	if (curr_hp <= 0)
		return false;
	return true;
}

void Monster::show_monster_status() {
	std::cout << "Monster status" << std::endl;
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defense: " << defense << std::endl;
	std::cout << "HP: " << curr_hp << " / " << max_hp << std::endl;
}
