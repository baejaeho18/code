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
		std::cout << "조사하고 싶은 플레이어의 이름을 입력하세요: ";
		std::cin >> target_name;
		if (bird_list->GetBirdNodeAsName(target_name)->GetBird()->DidKill())
			std::cout << target_name << "은(는) 이번 라운드에 누군가를 무참히 살해하였습니다..!" << std::endl;
		else
			std::cout << target_name << "은(는) 이번 라운드에 아무도 해치지 않았습니다." << std::endl;
	}
	else if (bird_list->GetNumDead() == 0) {
		std::cout << "염습 가능 대상이 없습니다." << std::endl;
	}
}