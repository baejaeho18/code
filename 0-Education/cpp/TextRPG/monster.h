#pragma once

enum Attribute { NONE, GRASS, WATER, FIRE };

class Monster {
	int attack;
	int defense;
	int attribute;
	int max_hp;
	int curr_hp;
	int reward;

	Monster(int difficulty);						// monster
	Monster(int attack, int defense, int max_hp);	// boss
};