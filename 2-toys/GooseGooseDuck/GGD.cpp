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
	// ���Һ� �ɷ� ���

	// ��ǥ

	// �¸� ����
}

bool GGD::IsGameOver() {
	// �÷��̾ �Ѹ� ���ų�

	// �¸������� �����Ǿ� ���� ���
	bool res = true;
	return res;
}

void GGD::PrintGameResult() {

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

	vote_ordered_bird_list->showList();
	role_ordered_bird_list->showList();
}

void GGD::SetSlayerLimit() {
	int max_slayer_limit;
	std::cout << "���� �Է��ϼ���: ";
	std::cin >> max_slayer_limit;
	Duck::SetSlayerLimit(max_slayer_limit);
}