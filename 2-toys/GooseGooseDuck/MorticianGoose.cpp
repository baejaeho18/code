#include "MorticianGoose.h"

MorticianGoose::MorticianGoose(const std::string& name)
	: Goose(name) {
	role_code = BirdRoleCode::kMorticianGoose;
}
MorticianGoose::~MorticianGoose() {};

void MorticianGoose::Skill(BirdList* bird_list) {

}