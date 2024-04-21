#pragma once

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

	void attack_basic();
	void attack_skill();
	void attack_fire();
	void attack_grass();
	void attack_Water();

	void level_up();

	void show_character_status();
};