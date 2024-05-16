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
	virtual ~Bird();
	std::string GetPlayerName() const;
	BirdRoleCode GetRoleCode() const;
	virtual void Skill(BirdList*)=0;
};

