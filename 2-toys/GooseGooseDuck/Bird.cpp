#include "Bird.h"
#include "BirdList.h"

Bird::Bird()
	: player_name(), role_code(), isDead(false) { }
Bird::Bird(std::string name_, BirdRoleCode code_) 
	: player_name(name_), role_code(code_), isDead(false) { }
Bird::~Bird() { }

void Bird::SetDead() { 
	isDead = true; 
};
