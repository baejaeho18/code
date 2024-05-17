#include "DodoBird.h"

DodoBird::DodoBird(const std::string& name)
	: Bird(name, BirdRoleCode::kDodoBird) { }

DodoBird::~DodoBird() {};

void DodoBird::Skill(BirdList* bird_list) {
	std::cout << player_name << "님 당신은 도도새입니다." << std::endl;
	std::cout << "당신은 능력이 없는 조류입니다." << std::endl;
}