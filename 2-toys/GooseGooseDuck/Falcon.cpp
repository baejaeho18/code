#include "Falcon.h"
#include "BirdList.h"

Falcon::Falcon(const std::string& name)
	: Bird(name, BirdRoleCode::kFalcon) { }

Falcon::~Falcon() {};

void Falcon::Skill(BirdList* bird_list) {
	char choice;
	std::cout << player_name << "�� ����� �۰���Դϴ�." << std::endl;
	std::cout << "������ ����Ͻðڽ��ϱ�? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y') {
		std::string target_name;
		std::cout << "�����ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		std::cin >> target_name;
		bird_list->Kill(target_name);
		std::cout << "��ü �޽���: " << target_name << "��(��) ������ ���ش��Ͽ����ϴ�.." << std::endl;
		killed = true;
	}
}

//void Falcon::Vote(BirdList* vote_list) {
//	std::cout << player_name << "��";
//	std::cout << "�� �۰���̹Ƿ� ��ȿǥ�� �ڵ� ��ǥ�˴ϴ�." << std::endl;
//}
