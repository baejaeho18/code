#include "menu.h"

bool start_game() {
	std::cout << "========================================================" << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << " #######                #    ######  ######   ##### " << std::endl;
	std::cout << "    #    ####  #    # #####  #     # #     # #     # " << std::endl;
	std::cout << "    #   #    #  #  #    #    #     # #     # # " << std::endl;
	std::cout << "    #   #####    ##     #    ######  ######  #  #### " << std::endl;
	std::cout << "    #   #        ##     #    #   #   #       #     # " << std::endl;
	std::cout << "    #   #       #  #    #    #    #  #       #     # " << std::endl;
	std::cout << "    #    ##### #    #   #    #     # #        ##### " << std::endl;
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

int progress_game(Map& map) {
	map.show_map();
	std::cout << "1. Choose direction" << std::endl;
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

int move_character(Map& map) {
	char direction, tmp;
	int room;
	std::cout << "Where do you want to go?" << std::endl;
	while (1) {
		std::cout << "> ";
		std::cin >> tmp;
		if (tmp == 'w' || tmp == 'a' || tmp == 's' || tmp == 'd') {
			direction = tmp;
			if (room = map.movable(direction))
				// direction으로 움직였을 때, room 이름 반환
				return room;
			else
				std::cout << "You cannot move to that direction." << std::endl;
		}
	}
}

void random_encounter(Character& gamer) {
	std::cout << "Random encounter!" << std::endl;
	std::cout << std::endl;
	// 0~3 임의의 숫자 고르고
	int r = rand() % 4;
	// 0이면 남은 HP 30%감소
	if (r == 0) {
		gamer.percentage_damage(0.3);
		std::cout << "You lost HP..." << std::endl;
	}
	// 1이면 잃은 HP 30% 회복
	else if (r == 1) {
		gamer.percentage_restore(0.3);
		std::cout << "You restored HP" << std::endl;
	}
	// 2이면 100 Gold 증가
	else if (r == 2) {
		gamer.looting_gold(100);
		std::cout << "You found 100 gold!" << std::endl;
	}
	// 3이면 nothing happen
	else {	// if (r == 3) {
		std::cout << "Nothing happened..." << std::endl;
	}
}

int fight(Character& gamer, Monster& enemy) {
	std::cout << "Wild monster appeared!" << std::endl;
	std::cout << std::endl;
	while (1) {
		std::cout << "=======================================" << std::endl;
		std::cout << "Character status" << std::endl;
		gamer.show_character_status();
		std::cout << "=======================================" << std::endl;
		enemy.show_monster_status();
		std::cout << "=======================================" << std::endl;
		std::cout << "Choose your action" << std::endl;
		std::cout << "1. Meele attack" << std::endl;
		std::cout << "2. Magic attack" << std::endl;
		std::cout << "3. Fire magic attack" << std::endl;
		std::cout << "4. Grass magic attack" << std::endl;
		std::cout << "5. Water magic attack" << std::endl;

		int opt;
		while (1) {
			std::cout << "> ";
			std::cin >> opt;
			if (opt == 1 || opt == 2 || opt == 3 || opt == 4 || opt == 5)
				break;
		}
		std::cout << std::endl;
		// player attack monster
		if (opt == 1)
			gamer.attack_basic(enemy);
		else if (opt == 2)
			gamer.attack_skill(enemy);
		else if (opt == 3)
			gamer.attack_fire(enemy);
		else if (opt == 4)
			gamer.attack_grass(enemy);
		else	// if (opt == 5)
			gamer.attack_water(enemy);
		// monster's turn
		enemy.attack_basic(gamer);

		std::cout << std::endl;
		if (!gamer.is_alive()) {
			std::cout << std::endl;
			std::cout << "You died..." << std::endl;
			return LOSE;
		}
		if (!enemy.is_alive()) {
			int reward = enemy.getReward();
			if (reward == -1) { // boss
				std::cout << std::endl;
				std::cout << "Game Clear!" << std::endl;
			}
			else if (0 < reward) { // mpnster
				std::cout << "You defeated the monster!" << std::endl;
				std::cout << "Reward: " << reward << " Gold, " << reward << " EXP" << std::endl;
				std::cout << std::endl;
				gamer.looting_exp(reward);
				gamer.looting_gold(reward);
				gamer.level_up_if_possible();
			}
			return WIN;
		}
	}
}

void shopping(Character& gamer) {
	Shop shop;
	int gold = gamer.getGold();
	std::cout << "Welcome to the item shop!" << std::endl;
	std::cout << "You have " << gold << " gold." << std::endl;
	std::cout << "=======================================" << std::endl;
	std::cout << "============== Item list ==============" << std::endl;
	std::cout << "=======================================" << std::endl;
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
	std::cout << "=======================================" << std::endl;

	int opt;
	while (1) {
		std::cout << "> ";
		std::cin >> opt;
		if (ATK_BUF <= opt && opt <= MP_BUF) {
			// available?
			if ((opt == ATK_BUF && !shop.attack_available())
				|| (opt == DEF_BUF && !shop.defense_available())
				|| (opt == EXP_BUF && !shop.exp_available())
				)
				std::cout << "Selected item is not available...\n" << std::endl;
			// enough gold?
			else if ((opt <= EXP_BUF && gold < 700) || (HP_BUF <= opt && gold < 500))
				std::cout << "You do not have enough gold...\n" << std::endl;
		}
		if (opt == 6)	// EXIT
			return;
	}
	gamer.purchase(opt, shop.items[opt]);	// opt, item(buf, cost)
	std::cout << "You bought an item!" << std::endl;
	std::cout << std::endl;
	std::cout << "======================================" << std::endl;
	// character status
	gamer.show_purchased_status(opt);
	std::cout << "=======================================" << std::endl;
	//shop item list
	std::cout << "Shop item list" << std::endl;
	std::cout << "1. Attack +10 (700 Gold) ";
	if (shop.attack_available())
		std::cout << "(Available)" << std::endl;
	else if (opt == ATK_BUF)
		std::cout << "(Available) => (Sold Out)" << std::endl;
	else 
		std::cout << "(Sold Out)" << std::endl;
	std::cout << "2. Defense +5 (700 Gold) ";
	if (shop.defense_available())
		std::cout << "(Available)" << std::endl;
	else if (opt == DEF_BUF)
		std::cout << "(Available) => (Sold Out)" << std::endl;
	else
		std::cout << "(Sold Out)" << std::endl;
	std::cout << "3. Exp +300 (700 Gold) ";
	if (shop.exp_available())
		std::cout << "(Available)" << std::endl;
	else if (opt == EXP_BUF)
		std::cout << "(Available) => (Sold Out)" << std::endl;
	else
		std::cout << "(Sold Out)" << std::endl;
	std::cout << "4. Restore HP (500 Gold) (Always available)" << std::endl;
	std::cout << "5. Restore MP (500 Gold) (Always available)" << std::endl;
	std::cout << "=======================================" << std::endl;
	std::cout << std::endl;
}
