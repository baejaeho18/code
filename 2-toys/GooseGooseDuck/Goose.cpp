#include "Goose.h"

#include <iostream>

Goose::Goose(const std::string& name)
	: Bird(name, BirdRoleCode::kGoose) { }

Goose::~Goose() { }

void Goose::Skill(BirdList*) {
	std::cout << player_name << "님 당신은 거위입니다." << std::endl;
	std::cout << "당신은 능력이 없는 조류입니다." << std::endl;
}