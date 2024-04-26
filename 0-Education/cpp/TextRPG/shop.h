#pragma once

#include <iostream>

#define MAX 9999

enum Items {ATK_BUF = 1, DEF_BUF, EXP_BUF, HP_BUF, MP_BUF};

struct Item {
	char name[11];
	int buf;
	int cost;
	int inventory;
};

class Shop {

public:
	Item items[6] = {
		{},
		{ "Attack", 10, 700, 1},
		{ "Defense", 5, 700, 1 },
		{ "Exp", 300, 700, 1 },
		{ "Restore HP", MAX, 500, MAX},
		{ "Restore MP", MAX, 500, MAX}
	};

	void show_item_list();
	void show_item_list_changed(int opt);
	bool available(int opt);

	bool attack_available();
	bool defense_available();
	bool exp_available();

	//void show_item_list(int gamer_gold);
};
