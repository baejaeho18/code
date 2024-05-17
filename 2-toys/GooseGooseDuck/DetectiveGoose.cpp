#include "DetectiveGoose.h"
#include "BirdList.h"

DetectiveGoose::DetectiveGoose(const std::string& name)
	: Goose(name) {
	role_code = BirdRoleCode::kDetectiveGoose;
}
DetectiveGoose::~DetectiveGoose() {};

void DetectiveGoose::Skill(BirdList* bird_list) {
	char choice;
	std::cout << player_name << "�� ����� Ž�� �����Դϴ�." << std::endl;
	std::cout << "���縦 ����Ͻðڽ��ϱ�? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y') {
		std::string target_name;
		std::cout << "�����ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		std::cin >> target_name;
		if (bird_list->GetBirdNodeAsName(target_name)->GetBird()->DidKill())
			std::cout << target_name << "��(��) �̹� ���忡 �������� ������ �����Ͽ����ϴ�..!" << std::endl;
		else
			std::cout << target_name << "��(��) �̹� ���忡 �ƹ��� ��ġ�� �ʾҽ��ϴ�." << std::endl;
	}
}