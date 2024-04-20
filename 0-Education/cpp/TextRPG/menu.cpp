#include "menu.h"

bool start_game() {
	std::cout << "========================================================" << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << " ####### ###### ###### ##### " << std::endl;
	std::cout << " # ###### # # ##### # # # # # # " << std::endl;
	std::cout << " # # # # # # # # # # " << std::endl;
	std::cout << " # ##### ## # ###### ###### # #### " << std::endl;
	std::cout << " # # ## # # # # # # " << std::endl;
	std::cout << " # # # # # # # # # # " << std::endl;
	std::cout << " # ###### # # # # # # ##### " << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << std::endl;
	std::cout << "----- Menu -----" << std::endl;
	std::cout << "1. Start game" << std::endl;
	std::cout << "2. Exit" << std::endl;
	
	int opt;
	while(1) {
		std::cout << "> ";
		std::cin >> opt;
		if (opt == 1)
			return true;
		else if (opt == 2)
			return false;
	}
}

int progress_game() {
	show_map();
	std::cout << "1. Choose tmp" << std::endl;
	std::cout << "2. Show character status" << std::endl;
	std::cout << "3. Exit game" << std::endl;

	int opt;
	while (1) {
		std::cout << "> ";
		std::cin >> opt;
		if (opt == 1 || opt == 2 || opt == 3)
			return opt;
	}
}

char move_character() {
	char direction, tmp;
	std::cout << "Where do you want to go?" << std::endl;
	while (1) {
		std::cout << "> ";
		std::cin >> tmp;
		if (tmp == 'w' || tmp == 'a' || tmp == 's' || tmp == 'd') {
			direction = tmp;
			// if not possible
			//if (gamer.movable(direction))
			//	break;
			//else
			//	std::cout << "You cannot move to that tmp." << std::endl;
		}
	}
}