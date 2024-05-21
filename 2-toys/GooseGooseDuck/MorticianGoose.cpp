#include "MorticianGoose.h"
#include "BirdList.h"

MorticianGoose::MorticianGoose(const std::string& name)
	: Goose(name) {
	role_code = BirdRoleCode::kMorticianGoose;
}
MorticianGoose::~MorticianGoose() {};

void MorticianGoose::Skill(BirdList* bird_list) {
	char choice;
	std::cout << player_name << "님 당신은 장의사 거위입니다." << std::endl;
	std::cout << "염습를 사용하시겠습니까? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y' && bird_list->GetNumDead() != 0) {
		std::string target_name;
		std::string target_role;
		std::cout << "염습하고 싶은 플레이어의 이름을 입력하세요: ";
		std::cin >> target_name;
		BirdRoleCode code = bird_list->GetBirdNodeAsName(target_name)->GetBird()->GetRoleCode();
		if (code == BirdRoleCode::kFalcon)
			target_role = "송골매";
		else if (code == BirdRoleCode::kAssassinDuck)
			target_role = "암살자 오리";
		else if (code == BirdRoleCode::kDuck)
			target_role = "오리";
		else if (code == BirdRoleCode::kDetectiveGoose)
			target_role = "탐정 거위";
		else if (code == BirdRoleCode::kMorticianGoose)
			target_role = "장위사 거위";
		else if (code == BirdRoleCode::kGoose)
			target_role = "거위";
		else if (code == BirdRoleCode::kDodoBird)
			target_role = "도도새";
		std::cout << target_name << "의 역할은 " << target_role << "입니다." << std::endl;
	}
	else if (bird_list->GetNumDead() == 0) {
		std::cout << "염습 가능 대상이 없습니다." << std::endl;
	}
}