#include "Duck.h"
#include "BirdList.h"

int Duck::slayer_limit = 1;
int Duck::slayer_count = 0;

Duck::Duck(const std::string& name)
	: Bird(name, BirdRoleCode::kDuck) {
	killed = false;
}

Duck::~Duck() {};

void Duck::Skill(BirdList* bird_list) {
	char choice;
	std::cout << player_name << "님 당신은 오리입니다." << std::endl;
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
	else {
		std::cout << "라운드당 오리 진영의 살조제한 횟수에 도달했습니다." << std::endl;
	}
}

void Duck::SetSlayerLimit(int limit) {
	slayer_limit = limit;
}

void Duck::ResetSlayerCount() {
	slayer_count = 0;
}

void Duck::ResetKilled() {
	killed = false;
}

bool Duck::DidKill() {
	return killed;
}
