#include "Goose.h"

#include <iostream>

Goose::Goose(const std::string& name)
	: Bird(name, BirdRoleCode::kGoose) { }

Goose::~Goose() { }

void Goose::Skill(BirdList*) {
	std::cout << "����� �ɷ��� ���� �����Դϴ�." << std::endl;
}