#pragma once
#include "Macro.h"
#include <iostream>

class BirdList;

class Bird
{
protected:
	std::string player_name;
	BirdRoleCode role_code;
	bool isDead;
public:
	Bird();
	Bird(std::string name_, BirdRoleCode code_);
	virtual ~Bird();

	std::string GetPlayerName() const { return this->player_name; };
	BirdRoleCode GetRoleCode() const { return role_code; };
	bool GetIsDead() const { return isDead; };
	void SetDead();

	virtual void Skill(BirdList*) = 0;
	//virtual void Vote(BirdList*) = 0;
};

