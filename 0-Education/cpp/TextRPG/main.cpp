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
	srand(time(NULL));

	while (1) {
		opt = progress_game();
		if (opt == 1) {
			int room = move_character();
			if (room == EMPTY) {
				// Continue
				continue;	// 이걸 쓰면 조금이라도 빨라지나?  ...별 차이 없더라
			}
			else if (room == RANDOM) {
				random_encounter(gamer);
			}
			else if (room == MONSTER) {
				int difficulty = 5;
				Monster enemy(difficulty);	// difficulty example
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