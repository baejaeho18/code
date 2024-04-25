#pragma once

#include <iostream>
#include "shop.h"
#include "monster.h"

class Monster;

class Character {
	int prev_level;
	int prev_attack;
	int prev_defense;
	int prev_max_hp;
	int prev_max_mp;
	int prev_max_exp;
	int prev_curr_hp;
	int prev_curr_mp;
	int prev_curr_exp;

	int gold;
	int level;
	int attack;
	int defense;
	int max_hp;
	int curr_hp;
	int max_mp;
	int curr_mp;
	int max_exp;
	int curr_exp;

public:
	Character();
	~Character();

	int getGold() const;
	//int getLevel() const;
	//int getAttack() const;
	//int getDefense() const;
	//int getMaxHP() const;
	//int getCurrHP() const;
	//int getMaxMP() const;
	//int getCurrMP() const;
	//int getMaxExp() const;
	//int getCurrExp() const;
	//void setCurrHP(int value);

	// level up
	void level_up_if_possible();
	// fight
	void attack_basic(Monster& enemy);
	void attack_skill(Monster& enemy);
	void attack_fire(Monster& enemy);
	void attack_grass(Monster& enemy);
	void attack_water(Monster& enemy);
	int injured(int damage);
	bool is_alive();	
	// show status
	void show_character_status();
	// shopping
	void show_purchased_status(int opt);
	void purchase(int opt, Item item);
	// random encounter
	void percentage_damage(double percentage);
	void percentage_restore(double percentage);
	void looting_gold(int gold_);
	void looting_exp(int exp_);
};