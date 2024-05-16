#pragma once
#include <string>
#include "Macro.h"

class BirdList;

class Bird
{
protected:
	std::string player_name;
	BirdRoleCode role_code;
public:
	Bird();
	Bird(std::string name_, BirdRoleCode code_);
	virtual ~Bird();
	std::string GetPlayerName() const { return this->player_name; };
	BirdRoleCode GetRoleCode() const { return role_code; };
	virtual void Skill(BirdList*)=0;
};

