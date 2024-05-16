#include "Duck.h"

int Duck::slayer_limit = 1;
int Duck::slayer_count = 0;

Duck::Duck(const std::string& name)
	: Bird(name, BirdRoleCode::kDuck) { }

Duck::~Duck() {};

void Duck::Skill(BirdList* bird_list) {

}


void Duck::SetSlayerLimit(int limit) {
	slayer_limit = limit;
}