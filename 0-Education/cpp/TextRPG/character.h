#pragma once

#include <iostream>
#include "shop.h"
#include "monster.h"

class Monster;

class Character {
public:
	int attack;
	int defense;
	int gold;
	int level;
	int max_hp;
	int curr_hp;
	int max_mp;
	int curr_mp;
	int max_exp;
	int curr_exp;

	int prev_level;
	int prev_attack;
	int prev_defense;
	int prev_max_hp;
	int prev_max_mp;
	int prev_max_exp;
	int prev_curr_hp;
	int prev_curr_mp;
	int prev_curr_exp;

	Character();

	void attack_basic(Monster& enemy);
	void attack_skill(Monster& enemy);
	void attack_fire(Monster& enemy);
	void attack_grass(Monster& enemy);
	void attack_water(Monster& enemy);

	int injured(int damage);

	bool is_alive();
	void level_up_if_possible();
	void show_character_status();

	void purchase(int opt, Item item);
};