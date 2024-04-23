#include "shop.h"

bool Shop::attack_available() {
	if (attack.inventory <= 0)
		return false;
	return true;
}

bool Shop::defense_available() {
	if (defense.inventory <= 0)
		return false;
	return true;
}

bool Shop::exp_available() {
	if (exp.inventory <= 0)
		return false;
	return true;
}

//void Shop::show_item_list(int gamer_gold) {
//	std::cout << "Welcome to the item shop!" << std::endl;
//	std::cout << "You have" << gamer_gold << "gold." << std::endl;
//	std::cout << "=====================================" << std::endl;
//	std::cout << "============== Item list ============" << std::endl;
//	std::cout << "=====================================" << std::endl;
//	std::cout << std::endl;
//	std::cout << "1. Attack +10 (700 Gold) ";
//	if (attack_available())
//		std::cout << "(Available)" << std::endl;
//	else
//		std::cout << "(Sold Out)" << std::endl;
//	std::cout << "2. Defense +5 (700 Gold) ";
//	if (defense_available())
//		std::cout << "(Available)" << std::endl;
//	else
//		std::cout << "(Sold Out)" << std::endl;
//	std::cout << "3. Exp +300 (700 Gold) ";
//	if (exp_available())
//		std::cout << "(Available)" << std::endl;
//	else
//		std::cout << "(Sold Out)" << std::endl;
//	std::cout << "4. Restore HP (500 Gold) (Always available)" << std::endl;
//	std::cout << "5. Restore MP (500 Gold) (Always available)" << std::endl;
//	std::cout << "6. Exit shop" << std::endl;
//	std::cout << std::endl;
//	std::cout << "=====================================" << std::endl;
//}