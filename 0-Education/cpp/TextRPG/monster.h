#pragma once

#include <cstdlib>

enum Attribute { NONE, GRASS, WATER, FIRE };

class Monster {
	int attack;
	int defense;
	int attribute;
	int max_hp;
	int curr_hp;
	int reward;

public:
	Monster(int difficulty);						// monster
	Monster(int attack_, int defense_, int hp_);	// boss
};