#pragma once
#include "character.h"
#include "monster.h"
#include "shop.h"
#include "map.h"

#include <cstdlib>


enum Room { EMPTY, RANDOM, MONSTER, SHOP, BOSS };
enum Result { LOSE, WIN };

bool start_game();
int progress_game();
int move_character();

void random_encounter(Character gamer);
int fight(Character gamer, Monster enemy);
void shopping(Character gamer);