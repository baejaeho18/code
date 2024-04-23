#include "character.h"

Character::Character() {
	attack = 10;
	defense = 2;
	gold = 0;
	level = 1;
	curr_hp = max_hp = 100;
	curr_mp = max_mp = 20;
	max_exp = 100;
	curr_exp = 0;
	prev_buf_value = 0;
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
	cout << "EXP: " << curr_exp << " / " << curr_exp << endl;
	cout << endl;
}

void Character::purchase(int opt, Item item) {
	if (opt == 1) {
		prev_buf_value = attack;
		attack = prev_buf_value + item.buf;
		gold -= item.cost;
	}
	else if (opt == 2) {
		prev_buf_value = defense;
		attack = prev_buf_value + item.buf;
	}
	else if (opt == 3) {
		prev_buf_value = curr_exp;
		curr_exp = prev_buf_value + 300;
		// levelup
		while (max_exp < curr_exp)
			level_up();
	}
	else if (opt == 4) {
		prev_buf_value = attack;
		curr_hp = max_hp;
	}
	else if (opt == 5) {
		prev_buf_value = curr_mp;
		curr_mp = max_mp;
	}
}