#pragma once
#include <iostream>
#include <cstdlib>
#include "character.h"

#define ROUND 0.5;

class Character;
enum Attribute { BASIC, NONE, GRASS, WATER, FIRE };

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
	// ~Monster();	// No need

	int getReward();

	void attack_basic(Character& gamer);
	int injured(int damage);
	int injured_skill(int damage);
	int injured_fire(int damage);
	int injured_grass(int damage);
	int injured_water(int damage);

	bool is_alive();
	void show_monster_status();
};