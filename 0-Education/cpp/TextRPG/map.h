#pragma once

#include <iostream>

enum Room { EMPTY = 1, RANDOM, MONSTER, SHOP, BOSS };

class Map {
	int x, y;	// current position

	enum Visit { MYST, VISIT };
	int visited[8][8];
	int mapping[8][8];

public:
	Map();
	void show_map();
	int movable(char direction);
	int distance();
};