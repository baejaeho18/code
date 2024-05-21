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
		std::cout << "------------���� ���� �޴�-------------\n";
		std::cout << "1. �÷��̾� �߰�\n";
		std::cout << "2. ����� ���� ���� ���� ���� Ƚ�� ����\n";
		std::cout << "3. ���� �����ϱ�!\n";
		std::cout << "---------------------------------------\n";
		std::cout << "�޴� ��ȣ�� �Է��ϼ���: ";
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
			// 1.3 ���� �����ϱ�!
			if (IsGameOver()) {
				std::cout << "������ ������ �� �����ϴ�!!" << std::endl;
			}
			else {
				std::cout << "���� ����!!" << std::endl;
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
	std::cout << "�÷��̾��� �̸��� �Է����ּ���: ";
	std::cin >> player_name;

	int role_code;
	std::cout << "���� ��ȣ�� �Է����ּ���: ";
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
	std::cout << "���� �Է��ϼ���: ";
	std::cin >> max_slayer_limit;
	Duck::SetSlayerLimit(max_slayer_limit);
}

bool GGD::IsGameOver() {
	// �÷��̾ �Ѹ� ���ų�
	//std::cout << vote_ordered_bird_list->GetNumAliveBird() << std::endl;
	if (vote_ordered_bird_list->isEmpty())
		return true;

	// �¸������� �����Ǿ� ���� ���
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
	// �ʱ�ȭ
	Duck::ResetSlayerCount();
	role_ordered_bird_list->ResetKilled();
	vote_ordered_bird_list->ResetVote();
	std::cout << "----------------Round " << round << "----------------" << std::endl;
	// ���Һ� �ɷ� ���
	role_ordered_bird_list->UseSkills();
	vote_ordered_bird_list->Kills(role_ordered_bird_list);
	// ��ǥ
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
		std::cout << "��ü �޽���: ������ �¸��Դϴ�!" << std::endl;
	else if (winner == Winner::wDuck)
		std::cout << "��ü �޽���: ������ �¸��Դϴ�!" << std::endl;
	else if (winner == Winner::wFalcon)
		std::cout << "��ü �޽���: �۰���� �¸��Դϴ�!" << std::endl;
	else if (winner == Winner::wDodo)
		std::cout << "��ü �޽���: �������� �¸��Դϴ�!" << std::endl;
}

