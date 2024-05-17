#include "DodoBird.h"

DodoBird::DodoBird(const std::string& name)
	: Bird(name, BirdRoleCode::kDodoBird) { }

DodoBird::~DodoBird() {};

void DodoBird::Skill(BirdList* bird_list) {
	std::cout << player_name << "�� ����� �������Դϴ�." << std::endl;
	std::cout << "����� �ɷ��� ���� �����Դϴ�." << std::endl;
}