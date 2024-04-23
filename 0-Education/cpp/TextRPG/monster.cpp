#include "monster.h"

// Monster
Monster::Monster(int difficulty) {
	max_hp = 50 + (difficulty * 5);
	curr_hp = max_hp;
	attack = 5 + difficulty * 2;
	defense = 2 + difficulty / 2;
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