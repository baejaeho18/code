#include "shop.h"

bool Shop::attack_available() {
	if (items[ATK_BUF].inventory <= 0)
		return false;
	return true;
}

bool Shop::defense_available() {
	if (items[DEF_BUF].inventory <= 0)
		return false;
	return true;
}

bool Shop::exp_available() {
	if (items[EXP_BUF].inventory <= 0)
		return false;
	return true;
}

bool Shop::available(int opt) {
	return (0 < items[opt].inventory);
}

void Shop::show_item_list() {
	for (int i = 1; i < 6; i++) {
		if (i == 4 || i == 5) {
			std::cout << i << ". " << items[i].name << " (" << items[i].cost << " Gold) ";
			std::cout << "(Always available)" << std::endl;
		}
		else {
			std::cout << i << ". " << items[i].name << " +" << items[i].buf << " (" << items[i].cost << " Gold) ";
			if (available(i))
				std::cout << "(Available)" << std::endl;
			else
				std::cout << "(Sold Out)" << std::endl;
		}
	}
	std::cout << "6. Exit shop" << std::endl;
}

void Shop::show_item_list_changed(int opt) {
	for (int i = 1; i < 6; i++) {
		if (i == 4 || i == 5) {
			std::cout << i << ". " << items[i].name << " (" << items[i].cost << " Gold) ";
			std::cout << "(Always available)" << std::endl;
		}
		else {
			std::cout << i << ". " << items[i].name << " +" << items[i].buf << " (" << items[i].cost << " Gold) ";
			if (available(i))
				std::cout << "(Available)" << std::endl;
			else if (opt == i)
				std::cout << "(Available) => (Sold Out)" << std::endl;
			else
				std::cout << "(Sold Out)" << std::endl;
		}
	}
}