#pragma once

//#include <iostream>

#define MAX 9999

enum Items {ATK_BUF = 1, DEF_BUF, EXP_BUF, HP_BUF, MP_BUF};

struct Item {
	int buf;
	int cost;
	int inventory;
};

class Shop {

	Item attack = { 10, 700, 1 };
	Item defense = { 5, 700, 1 };
	Item exp = { 300, 700, 1 };
	Item hp = { MAX, 500, MAX };
	Item mp = { MAX, 500, MAX };

public:
	Item items[6] = {
		{},
		{ 10, 700, 1 },
		{ 5, 700, 1 },
		{ 300, 700, 1 },
		{ MAX, 500, MAX },
		{ MAX, 500, MAX }
	};

	bool attack_available();
	bool defense_available();
	bool exp_available();

	//void show_item_list(int gamer_gold);
};
