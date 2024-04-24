#include "map.h"

Map::Map() {
	x = y = 0;
	visited[8][8] =
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

	mapping[8][8] =
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
}

void Map::show_map() {
	int i, j;
	std::cout << "┌───┬───┬───┬───┬───┬───┬───┬───┐" << std::endl;
	for (j = 0; j < 8; j++) {
		for (i = 0; i < 8; i++) {
			std::cout << "│";
			if (j == y && i == x)
				std::cout << "You";
			else if (visited[j][i] == MYST)
				std::cout << " ? ";
			else // if (visited[j][i] == VISIT)
				std::cout << "   ";
		}
		std::cout << "│" << std::endl;
		if (j != 7)
			std::cout << "├───┼───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	}
	std::cout << "└───┴───┴───┴───┴───┴───┴───┴───┘" << std::endl;
}

int Map::movable(char direction) {
	// 가장자리일 때 wasd 움직임 불가능
	if ( (y == 0 && direction == 'w') || (y == 7 && direction == 's')
		|| (x == 0 && direction == 'a') || (x == 7 && direction == 'w')  )
		return 0;

	if (mapping[y][x] != SHOP)
		mapping[y][x] = EMPTY;
	// x,y좌표 바꾸고
	if (direction == 'w')		// up
		y--;
	else if (direction == 'a') // left
		x--;
	else if (direction == 's') // down
		y++;
	else if (direction == 'd') // right
		x++;
	// else wouldn't be happen	
	visited[y][x] = VISIT;
	return mapping[y][x];
}

int Map::distance() {
	return x + y;
}