#pragma once
#include "character.h"
#include "monster.h"
#include "shop.h"
#include "map.h"


enum Room { EMPTY, RANDOM, MONSTER, SHOP, BOSS };
enum Result { LOSE, WIN };

bool start_game();		// start or not
int progress_game();	// return 1. move 2. show_status 3. exit
int move_character();	// arriving Room is Empty or Random or Monster or Shop or Boss

void random_encounter(Character &gamer);
int fight(Character gamer, Monster enemy);	// LOSE or WIN
void shopping(Character gamer);
