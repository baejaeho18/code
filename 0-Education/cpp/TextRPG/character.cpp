#include "character.h"

Character::Character() {
	prev_attack = attack = 10;
	prev_defense =defense = 2;
	gold = 0;
	prev_level = level = 1;
	prev_curr_hp = prev_max_hp = curr_hp = max_hp = 100;
	prev_curr_mp = prev_max_mp = curr_mp = max_mp = 20;
	prev_max_exp = max_exp = 100;
	prev_curr_exp = curr_exp = 0;
}

void attack_basic(){
	
}

void attack_skill(){
	
}

void attack_fire(){
	
}

void attack_grass(){

}

void attack_water(){

}

void Character::level_up() {

}

void Character::show_character_status() {
	using namespace std;
	cout << endl;
	cout << "Level: " << level << endl;
	cout << "Attack: " << attack << endl;
	cout << "Defense: " << defense << endl;
	cout << "Gold: " << gold << endl;
	cout << "HP: " << curr_hp << " / " << max_hp << endl;
	cout << "MP: " << curr_mp << " / " << max_mp << endl;
	cout << "EXP: " << curr_exp << " / " << max_exp << endl;
	cout << endl;
}

void Character::purchase(int opt, Item item) {
	if (opt == 1) {
		prev_attack = attack;
		attack += item.buf;
	}
	else if (opt == 2) {
		prev_defense = defense;
		defense += item.buf;
	}
	else if (opt == 3) {
		prev_curr_exp = curr_exp;
		curr_exp += item.buf;
		// levelup
		while (max_exp < curr_exp)
			level_up();
	}
	else if (opt == 4) {
		prev_curr_hp = curr_hp;
		curr_hp = max_hp;
	}
	else if (opt == 5) {
		prev_curr_mp = curr_mp;
		curr_mp = max_mp;
	}
	// else wouldn't be happen
	gold -= item.cost;
}