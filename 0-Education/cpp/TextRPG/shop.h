#pragma once

#define MAX 9999

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
	bool attack_available();
	bool defense_available();
	bool exp_available();

};
