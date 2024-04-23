#include "monster.h"

Monster::Monster(int difficulty) {
	max_hp = 50 + (difficulty * 5);
	curr_hp = max_hp;
	attack = 5 + difficulty * 2;
	defense = 2 + difficulty / 2;
	reward = 100 + difficulty * 10;
	attribute = rand() % 4;
}

Monster::Monster(int attack, int defense, int hp) {
	max_hp = hp;
	curr_hp = hp;
	this->attack = attack;
	this->defense = defense;
	reward = -1;
	attribute = rand() % 4;
}