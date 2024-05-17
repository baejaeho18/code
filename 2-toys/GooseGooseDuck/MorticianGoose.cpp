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
		std::cout << "�����ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		std::cin >> target_name;
		if (bird_list->GetBirdNodeAsName(target_name)->GetBird()->DidKill())
			std::cout << target_name << "��(��) �̹� ���忡 �������� ������ �����Ͽ����ϴ�..!" << std::endl;
		else
			std::cout << target_name << "��(��) �̹� ���忡 �ƹ��� ��ġ�� �ʾҽ��ϴ�." << std::endl;
	}
	else if (bird_list->GetNumDead() == 0) {
		std::cout << "���� ���� ����� �����ϴ�." << std::endl;
	}
}