#pragma once

#include <iostream>
#include "shop.h"
#include "monster.h"

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

	int prev_buf_value;

	Character();

	void attack_basic();
	void attack_skill();
	void attack_fire();
	void attack_grass();
	void attack_Water();

	void level_up();
	void show_character_status();

	void purchase(int opt, Item item);
};