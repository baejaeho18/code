#include "AssassinDuck.h"

AssassinDuck::AssassinDuck(const std::string& name)
	: Duck(name) {
	role_code = BirdRoleCode::kAssassinDuck;
}
AssassinDuck::~AssassinDuck() {};

void AssassinDuck::Skill(BirdList* bird_list) {

}