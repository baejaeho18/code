#pragma once
#include "BirdList.h"
#include "DodoBird.h"
#include "Falcon.h"
#include "AssassinDuck.h"
#include "DetectiveGoose.h"
#include "MorticianGoose.h"

class GGD
{
private:
	BirdList* role_ordered_bird_list;
	BirdList* vote_ordered_bird_list;
	int round;
	Winner winner;
public:
	// Do not change any function declaration from here //
	GGD(); 
	~GGD(); 
	void GameStart(); 
	void RoundProgress(); 
	bool IsGameOver(); 
	void PrintGameResult(); 
	// Do not change any function declaration to here //

	void AddPlayer(); // You can change the function declaration
	void SetSlayerLimit();
};

