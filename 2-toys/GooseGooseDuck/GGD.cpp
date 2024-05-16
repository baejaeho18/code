#include "GGD.h"
#include "Macro.h"

GGD::GGD() {
	role_ordered_bird_list = new BirdList();
	vote_ordered_bird_list = new BirdList();
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
	// 플레이어가 한명도 없거나

	// 승리조건이 만족되어 있을 경우
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

	Bird* temp = nullptr;
	switch (BirdRoleCode(role_code)) {
	case BirdRoleCode::kFalcon:
		temp = new Falcon(player_name);
		break;
	case BirdRoleCode::kAssassinDuck:
		temp = new AssassinDuck(player_name);
		break;
	case BirdRoleCode::kDuck:
		temp = new Duck(player_name);
		break;
	case BirdRoleCode::kDetectiveGoose:
		temp = new DetectiveGoose(player_name);
		break;
	case BirdRoleCode::kMorticianGoose:
		temp = new MorticianGoose(player_name);
		break;
	case BirdRoleCode::kGoose:
		temp = new Goose(player_name);
		break;
	case BirdRoleCode::kDodoBird:
		temp = new DodoBird(player_name);
		break;
	default:
		break;
	}

	if (temp != nullptr) {
		vote_ordered_bird_list->AddBirdNodeAsVoteOrder(new BirdNode(temp));
		role_ordered_bird_list->AddBirdNodeAsRoleOrder(new BirdNode(temp));
	}

	vote_ordered_bird_list->showList();
	role_ordered_bird_list->showList();
}

void GGD::SetSlayerLimit() {
	int max_slayer_limit;
	std::cout << "값을 입력하세요: ";
	std::cin >> max_slayer_limit;
	Duck::SetSlayerLimit(max_slayer_limit);
}