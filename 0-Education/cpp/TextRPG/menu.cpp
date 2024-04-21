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

int move_character() {
	char direction, tmp;
	std::cout << "Where do you want to go?" << std::endl;
	while (1) {
		std::cout << "> ";
		std::cin >> tmp;
		if (tmp == 'w' || tmp == 'a' || tmp == 's' || tmp == 'd') {
			direction = tmp;
			//if (movable(direction))
			//	break;
			//else
			//	std::cout << "You cannot move to that tmp." << std::endl;
		}
	}

	// direction으로 움직였을 때, room이름 반환
	return EMPTY;
}

void random_encounter(Character gamer) {
	std::cout << "Random encounter!" << std::endl;
	std::cout << std::endl;
	// 0~3 임의의 숫자 고르고
	int r = rand() % 4;
	// 0이면 HP 30%감소
	if (r == 0) {

		std::cout << "You lost HP..." << std::endl;
	}
	// 1이면 HP 30% 회복
	else if (r == 1) {

		std::cout << "You restored HP" << std::endl;
	}
	// 2이면 100 Gold 증가
	else if (r == 2) {

		std::cout << "You found 100 gold!" << std::endl;
	}
	// 3이면 nothing happen
	else {	// if (r == 3) {
		std::cout << "Nothing happened..." << std::endl;
	}
}

int fight(Character gamer, Monster enemy) {

	return LOSE;
}

void shopping(Character gamer) {
	Shop shop;
	std::cout << "Welcome to the item shop!" << std::endl;
	std::cout << "You have" << gamer.gold << "gold." << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << "============== Item list ============" << std::endl;
	std::cout << "=====================================" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Attack +10 (700 Gold) ";
	if (shop.attack_available())
		std::cout << "(Available)" << std::endl;
	else
		std::cout << "(Sold Out)" << std::endl;
	std::cout << "2. Defense +5 (700 Gold) ";
	if (shop.defense_available())
		std::cout << "(Available)" << std::endl;
	else
		std::cout << "(Sold Out)" << std::endl;
	std::cout << "3. Exp +300 (700 Gold) ";
	if (shop.exp_available())
		std::cout << "(Available)" << std::endl;
	else
		std::cout << "(Sold Out)" << std::endl;
	std::cout << "4. Restore HP (500 Gold) (Always available)" << std::endl;
	std::cout << "5. Restore MP (500 Gold) (Always available)" << std::endl;
	std::cout << "6. Exit shop" << std::endl;
	std::cout << std::endl;
	std::cout << "=====================================" << std::endl;

	int opt;
	while (1) {
		std::cout << "> ";
		std::cin >> opt;
		if (opt == 1 || opt == 2 || opt == 3 || opt == 4 || opt == 5 || opt == 6) {
			// available?

			// enough gold?
		}
	}

}
