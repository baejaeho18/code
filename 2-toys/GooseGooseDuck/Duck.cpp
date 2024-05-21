#include "Duck.h"
#include "BirdList.h"

int Duck::slayer_limit = 1;
int Duck::slayer_count = 0;

Duck::Duck(const std::string& name)
	: Bird(name, BirdRoleCode::kDuck) {
}

Duck::~Duck() {};

void Duck::Skill(BirdList* bird_list) {
	char choice;
	std::cout << player_name << "�� ����� �����Դϴ�." << std::endl;
	std::cout << "������ ����Ͻðڽ��ϱ�? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y' && slayer_count < slayer_limit) {
		std::string target_name;
		std::cout << "�����ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		std::cin >> target_name;
		bird_list->Kill(target_name);
		std::cout << "��ü �޽���: " << target_name << "��(��) ������ ���ش��Ͽ����ϴ�..!" << std::endl;
		slayer_count++;
		killed = true;
	}
	else if (choice == 'Y') {
		std::cout << "����� ���� ������ �������� Ƚ���� �����߽��ϴ�." << std::endl;
	}
}

void Duck::SetSlayerLimit(int limit) {
	slayer_limit = limit;
}

void Duck::ResetSlayerCount() {
	slayer_count = 0;
}
