#include "menu.h"
#include "character.h"

int main() {

	if (!start_game()) {
		std::cout << "Exit..." << std::endl;
		return 0;
	}
	std::cout << "Game start!" << std::endl;

	int opt;
	Character gamer;
	while (1) {
		opt = progress_game();
		if (opt == 1) {
			move_character();
		}
		if (opt == 2) {
			//gamer.show_character_status();
		}
		if (opt == 3) {
			std::cout << "Exit..." << std::endl;
			return 0;
		}
	}
	



	return 0;
}