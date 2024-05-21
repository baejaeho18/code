#include "GGD.h"
#include "Macro.h"

GGD::GGD() {
	role_ordered_bird_list = new BirdList();
	vote_ordered_bird_list = new BirdList();
	round = 1;
	winner = Winner::None;
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
			// 1.3 게임 시작하기!
			if (IsGameOver()) {
				std::cout << "게임을 시작할 수 없습니다!!" << std::endl;
			}
			else {
				std::cout << "게임 시작!!" << std::endl;
				return;
			}
			break;
		default:
			break;
		}
	}
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

	//vote_ordered_bird_list->showList();
	//role_ordered_bird_list->showList();
}

void GGD::SetSlayerLimit() {
	int max_slayer_limit;
	std::cout << "값을 입력하세요: ";
	std::cin >> max_slayer_limit;
	Duck::SetSlayerLimit(max_slayer_limit);
}

bool GGD::IsGameOver() {
	// 플레이어가 한명도 없거나
	//std::cout << vote_ordered_bird_list->GetNumAliveBird() << std::endl;
	if (vote_ordered_bird_list->isEmpty())
		return true;

	// 승리조건이 만족되어 있을 경우
	if (vote_ordered_bird_list->GetIsDodoWin())
		winner = Winner::wDodo;
	else if (vote_ordered_bird_list->IsFalconAlive() && vote_ordered_bird_list->GetNumAliveBird() <= 2)
		winner = Winner::wFalcon;
	else if (vote_ordered_bird_list->GetNumAliveDuck() > 0 &&
		vote_ordered_bird_list->GetNumAliveDuck() >= vote_ordered_bird_list->GetNumAliveBird() - vote_ordered_bird_list->GetNumAliveDuck())
		winner = Winner::wDuck;
	else if (vote_ordered_bird_list->GetNumAliveGoose() > 0 &&
		vote_ordered_bird_list->GetNumAliveDuck() <= 0 && !vote_ordered_bird_list->IsFalconAlive())
		winner = Winner::wGoose;
	else
		winner = Winner::None;
	//std::cout << vote_ordered_bird_list->GetNumAliveGoose() << vote_ordered_bird_list->GetNumAliveDuck() << vote_ordered_bird_list->IsFalconAlive() << std::endl;
	//std::cout << (int)winner << std::endl;
	if (winner != Winner::None)
		return true;
	return false;
}

void GGD::RoundProgress() {
	// 초기화
	Duck::ResetSlayerCount();
	role_ordered_bird_list->ResetKilled();
	vote_ordered_bird_list->ResetVote();
	std::cout << "----------------Round " << round << "----------------" << std::endl;
	// 역할별 능력 사용
	role_ordered_bird_list->UseSkills();
	vote_ordered_bird_list->Kills(role_ordered_bird_list);
	// 투표
	vote_ordered_bird_list->DoVotes();
	role_ordered_bird_list->Kills(vote_ordered_bird_list);
	//std::cout << "Goes well" << std::endl;
	round++;
	//vote_ordered_bird_list->ResetIsDodoWin();
	//vote_ordered_bird_list->DeleteDeadBird();
	//role_ordered_bird_list->DeleteDeadBird();
}

void GGD::PrintGameResult() {
	if (winner == Winner::wGoose)
		std::cout << "전체 메시지: 거위의 승리입니다!" << std::endl;
	else if (winner == Winner::wDuck)
		std::cout << "전체 메시지: 오리의 승리입니다!" << std::endl;
	else if (winner == Winner::wFalcon)
		std::cout << "전체 메시지: 송골매의 승리입니다!" << std::endl;
	else if (winner == Winner::wDodo)
		std::cout << "전체 메시지: 도도새의 승리입니다!" << std::endl;
}

