#pragma once

#include <iostream>

enum Room { EMPTY = 1, RANDOM, MONSTER, SHOP, BOSS };

class Map {
	int x, y;	// current position

	enum Visit{MYST, VISIT};
	int visited[8][8] =
	{
		{VISIT, MYST, MYST, MYST, MYST, MYST, MYST, MYST},
		{MYST, MYST, MYST, MYST, MYST, MYST, MYST, MYST},
		{MYST, MYST, MYST, MYST, MYST, MYST, MYST, MYST},
		{MYST, MYST, MYST, MYST, MYST, MYST, MYST, MYST},
		{MYST, MYST, MYST, MYST, MYST, MYST, MYST, MYST},
		{MYST, MYST, MYST, MYST, MYST, MYST, MYST, MYST},
		{MYST, MYST, MYST, MYST, MYST, MYST, MYST, MYST},
		{MYST, MYST, MYST, MYST, MYST, MYST, MYST, MYST},
	};

	const int mapping[8][8] =
	{
		{EMPTY,	 RANDOM, MONSTER,MONSTER,RANDOM, EMPTY,  MONSTER,MONSTER},
		{MONSTER,EMPTY,	 RANDOM, EMPTY,	 MONSTER,RANDOM, EMPTY,  RANDOM},
		{RANDOM, MONSTER,EMPTY,  EMPTY,  MONSTER,EMPTY,  MONSTER,MONSTER},
		{MONSTER,EMPTY,	 RANDOM, SHOP,	 MONSTER,MONSTER,EMPTY,  RANDOM},
		{MONSTER,MONSTER,EMPTY,	 RANDOM, EMPTY,  RANDOM, MONSTER,EMPTY},
		{EMPTY,	 RANDOM, MONSTER,EMPTY,	 MONSTER,EMPTY,  EMPTY,  RANDOM},
		{MONSTER,EMPTY,	 RANDOM, MONSTER,MONSTER,EMPTY,  RANDOM, MONSTER},
		{EMPTY,  EMPTY,	 MONSTER,EMPTY,  RANDOM, MONSTER,EMPTY,	 BOSS}
	};

public:
	Map();
	void show_map();
	int movable(char direction);
};