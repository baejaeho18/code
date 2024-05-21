// Do not change any code in this file
#include "GGD.h"

int main() {

	GGD game;
	game.GameStart();
	while (!game.IsGameOver()) {
		game.RoundProgress();
	}
	std::cout << game.IsGameOver();
	game.PrintGameResult();

	return 0;
}