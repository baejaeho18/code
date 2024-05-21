#include "AssassinDuck.h"
#include "BirdList.h"

AssassinDuck::AssassinDuck(const std::string& name)
	: Duck(name) {
	role_code = BirdRoleCode::kAssassinDuck;
	max_assassin_limit = 2;
	count_assassin = 0;
}
AssassinDuck::~AssassinDuck() {};

void AssassinDuck::Skill(BirdList* bird_list) {
	char choice;
	std::cout << player_name << "님 당신은 암살자 오리입니다." << std::endl;
	std::cout << "암살을 사용하시겠습니까? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y' && count_assassin < max_assassin_limit) {
		std::string target_name;
		int target_role;
		std::cout << "암살하고 싶은 플레이어의 이름을 입력하세요: ";
		std::cin >> target_name;
		std::cout << "암살하고 싶은 플레이어의 역할 번호를 입력하세요: ";
		std::cin >> target_role;
		if (bird_list->IsRoleCorrect(target_name, static_cast<BirdRoleCode>(target_role))) {
			bird_list->Kill(target_name);
			std::cout << "전체 메시지: " << target_name << "이(가) 무참히 살해당하였습니다..!" << std::endl;
			count_assassin++;
			killed = true;
		}
		else {
			std::cout << "전체 메시지: " << player_name << "은(는) 극단적 선택을 하였습니다." << std::endl;
			bird_list->Kill(player_name);
			return;
		}
	}
	else if (choice == 'Y') {
		std::cout << "더 이상 암살 능력을 사용할 수 없습니다!" << std::endl;
	}
	std::cout << "살조를 사용하시겠습니까? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y' && slayer_count < slayer_limit) {
		std::string target_name;
		std::cout << "살해하고 싶은 플레이어의 이름을 입력하세요: ";
		std::cin >> target_name;
		bird_list->Kill(target_name);
		std::cout << "전체 메시지: " << target_name << "이(가) 무참히 살해당하였습니다.." << std::endl;
		slayer_count++;
		killed = true;
	}
	else if (choice == 'Y') {
		std::cout << "라운드당 오리 진영의 살조제한 횟수에 도달했습니다." << std::endl;
	}
}