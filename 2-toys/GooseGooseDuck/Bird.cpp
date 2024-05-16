#include "Bird.h"

#include <iostream>

Bird::Bird() { }

Bird::Bird(std::string name_, BirdRoleCode code_) 
	: player_name(name_), role_code(code_) { }

Bird::~Bird() { }