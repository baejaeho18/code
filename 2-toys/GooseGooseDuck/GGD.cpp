#include <iostream>
#include <string>
#include "GGD.h"
#include "Macro.h"

GGD::GGD() {
	role_ordered_bird_list = new BirdList();
	vote_ordered_bird_list = new BirdList();
	max_slayer_limit = 1;
}
GGD::~GGD() {
	role_ordered_bird_list->~BirdList();
	vote_ordered_bird_list->~BirdList();
}
void GGD::GameStart() {
	int select;
	bool game_start = false;
	while (!game_start) {
		std::cout << "------------게임 설정 메뉴-------------\n";
		std::cout << "1. 플레이어 추가\n";
		std::cout << "2. 라운드당 오리 진영 살조 제한 횟수 설정\n";
		std::cout << "3. 게임 시작하기!\n";
		std::cout << "---------------------------------------\n";
		std::cout << "메뉴 번호를 입력하세요: ";
		std::cin >> select;

		switch (select)
		{
		case 1:
			AddPlayer();
			break;
		case 2:
			SetSlayerLimit();
			break;
		case 3:
			while (!IsGameOver()) {
				RoundProgress();
			}
			break;
		default:
			break;
		}
	}
}
void GGD::RoundProgress() {
	// 역할별 능력 사용

	// 투표

	// 승리 조건
}

bool GGD::IsGameOver() {
	bool res = true;
	return res;
}

void GGD::PrintGameResult() {

}

void GGD::AddPlayer() {
	std::string player_name;
	std::cout << "플레이어의 이름을 입력해주세요: ";
	std::cin >> player_name;
	
	int role_code;
	std::cout << "역할 번호를 입력해주세요: ";
	std::cin >> role_code;

	Bird *temp = nullptr;
	switch (BirdRoleCode(role_code)) {
	case BirdRoleCode::kFalcon:
		temp = new Falcon(player_name);
		break;
	case BirdRoleCode::kAssassinDuck:
		temp = new AssassinDuck(palyer_name);
		break;
	case BirdRoleCode::kDuck:
		break;
	case BirdRoleCode::kDetectiveGoose:
		break;
	case BirdRoleCode::kMorticianGoose:
		break;
	case BirdRoleCode::kGoose:
		break;
	case BirdRoleCode::kDodoBird:
		break;
	default:
		break;
	}

	if (temp != nullptr) {
		vote_ordered_bird_list->AddBirdNodeAsVoteOrder(new BirdNode(temp));
		role_ordered_bird_list->AddBirdNodeAsRoleOrder(new BirdNode(temp));
	}
}

void GGD::SetSlayerLimit() {
	std::cout << "값을 입력하세요";
}