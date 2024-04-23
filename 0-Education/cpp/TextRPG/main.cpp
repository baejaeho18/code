#include "menu.h"

int main() {

	if (!start_game()) {
		std::cout << "Exit..." << std::endl;
		return 0;
	}
	std::cout << "Game start!" << std::endl;	
	std::cout << std::endl;

	int opt;
	Map map;
	Character gamer;
	srand(time(NULL));

	while (1) {
		opt = progress_game(map);
		if (opt == 1) {
			int room = move_character(map);
			if (room == EMPTY) {
				continue;	// 이걸 쓰면 조금이라도 빨라지나?  ...별 차이 없더라
			}
			else if (room == RANDOM) {
				random_encounter(gamer);
				if (!gamer.is_alive())
					break;
			}
			else if (room == MONSTER) {
				Monster enemy(map.distance());
				if (fight(gamer, enemy) == LOSE)
					break;
			}
			else if (room == SHOP) {
				shopping(gamer);
			}
			else {	// if (room = BOSS) {
				Monster boss(30, 10, 200);
				fight(gamer, boss);
				break;
			}
		}
		else if (opt == 2) {
			std::cout << std::endl;
			gamer.show_character_status();
			std::cout << std::endl;
		}
		else { // if (opt == 3) {
			std::cout << "Exit..." << std::endl;
			break;
		}
	}

	return 0;
}