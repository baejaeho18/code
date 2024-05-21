#include "MorticianGoose.h"
#include "BirdList.h"

MorticianGoose::MorticianGoose(const std::string& name)
	: Goose(name) {
	role_code = BirdRoleCode::kMorticianGoose;
}
MorticianGoose::~MorticianGoose() {};

void MorticianGoose::Skill(BirdList* bird_list) {
	char choice;
	std::cout << player_name << "�� ����� ���ǻ� �����Դϴ�." << std::endl;
	std::cout << "������ ����Ͻðڽ��ϱ�? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y' && bird_list->GetNumDead() != 0) {
		std::string target_name;
		std::string target_role;
		std::cout << "�����ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		std::cin >> target_name;
		BirdRoleCode code = bird_list->GetBirdNodeAsName(target_name)->GetBird()->GetRoleCode();
		if (code == BirdRoleCode::kFalcon)
			target_role = "�۰��";
		else if (code == BirdRoleCode::kAssassinDuck)
			target_role = "�ϻ��� ����";
		else if (code == BirdRoleCode::kDuck)
			target_role = "����";
		else if (code == BirdRoleCode::kDetectiveGoose)
			target_role = "Ž�� ����";
		else if (code == BirdRoleCode::kMorticianGoose)
			target_role = "������ ����";
		else if (code == BirdRoleCode::kGoose)
			target_role = "����";
		else if (code == BirdRoleCode::kDodoBird)
			target_role = "������";
		std::cout << target_name << "�� ������ " << target_role << "�Դϴ�." << std::endl;
	}
	else if (bird_list->GetNumDead() == 0) {
		std::cout << "���� ���� ����� �����ϴ�." << std::endl;
	}
}