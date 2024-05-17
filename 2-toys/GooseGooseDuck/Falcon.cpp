#include "Falcon.h"
#include "BirdList.h"

Falcon::Falcon(const std::string& name)
	: Bird(name, BirdRoleCode::kFalcon) { }

Falcon::~Falcon() {};

void Falcon::Skill(BirdList* bird_list) {
	char choice;
	std::cout << player_name << "님 당신은 송골매입니다." << std::endl;
	std::cout << "살조를 사용하시겠습니까? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y') {
		std::string target_name;
		std::cout << "살해하고 싶은 플레이어의 이름을 입력하세요: ";
		std::cin >> target_name;
		bird_list->Kill(target_name);
		std::cout << "전체 메시지: " << target_name << "이(가) 무참히 살해당하였습니다.." << std::endl;
		killed = true;
	}
}

//void Falcon::Vote(BirdList* vote_list) {
//	std::cout << player_name << "님";
//	std::cout << "은 송골매이므로 무효표에 자동 투표됩니다." << std::endl;
//}
