#include "menu.h"

int main() {

	if (!start_game()) {
		std::cout << "Exit..." << std::endl;
		return 0;
	}
	std::cout << "Game start!" << std::endl;	
	std::cout << std::endl;

	int opt;
	Character gamer;
	while (1) {
		opt = progress_game();
		if (opt == 1) {
			int room = move_character();
			if (room == EMPTY) {
				// Continue
			}
			else if (room == RANDOM) {
				random_encounter(gamer);
			}
			else if (room == MONSTER) {
				Monster enemy(5);
				if (fight(gamer, enemy) == WIN){
					gamer.level_up();
				}
				else {	// if (fight(gamer, boss0 == LOSE) {
					std::cout << std::endl;
					std::cout << "You died..." << std::endl;
					break;
				}
			}
			else if (room == SHOP) {
				shopping(gamer);
			}
			else {	// if (room = BOSS) {
				Monster boss(30, 10, 200);
				if (fight(gamer, boss) == WIN) {
					std::cout << "Game Clear!" << std::endl;
				}
				else {	// if (fight(gamer, boss0 == LOSE) {
					std::cout << std::endl;
					std::cout << "You died..." << std::endl;
				}
				break;
			}
		}
		else if (opt == 2) {
			gamer.show_character_status();
		}
		else { // if (opt == 3) {
			std::cout << "Exit..." << std::endl;
			break;
		}
	}

	return 0;
}