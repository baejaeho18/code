#include "DetectiveGoose.h"

DetectiveGoose::DetectiveGoose(const std::string& name)
	: Goose(name) {
	role_code = BirdRoleCode::kDetectiveGoose;
}
DetectiveGoose::~DetectiveGoose() {};

void DetectiveGoose::Skill(BirdList* bird_list) {

}