#include "AssassinDuck.h"
#include "BirdList.h"

AssassinDuck::AssassinDuck(const std::string& name)
	: Duck(name) {
	role_code = BirdRoleCode::kAssassinDuck;
	max_assassin_limit = 2;
	count_assassin = 0;
}
AssassinDuck::~AssassinDuck() {};

void AssassinDuck::Skill(BirdList* bird_list) {
	char choice;
	std::cout << player_name << "�� ����� �ϻ��� �����Դϴ�." << std::endl;
	std::cout << "�ϻ��� ����Ͻðڽ��ϱ�? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y' && count_assassin < max_assassin_limit) {
		std::string target_name;
		int target_role;
		std::cout << "�ϻ��ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		std::cin >> target_name;
		std::cout << "�ϻ��ϰ� ���� �÷��̾��� ���� ��ȣ�� �Է��ϼ���: ";
		std::cin >> target_role;
		if (bird_list->IsRoleCorrect(target_name, static_cast<BirdRoleCode>(target_role))) {
			bird_list->Kill(target_name);
			std::cout << "��ü �޽���: " << target_name << "��(��) ������ ���ش��Ͽ����ϴ�..!" << std::endl;
			count_assassin++;
			killed = true;
		}
		else {
			std::cout << "��ü �޽���: " << player_name << "��(��) �ش��� ������ �Ͽ����ϴ�." << std::endl;
			bird_list->Kill(player_name);
			return;
		}
	}
	else if (choice == 'Y') {
		std::cout << "�� �̻� �ϻ� �ɷ��� ����� �� �����ϴ�!" << std::endl;
	}
	std::cout << "������ ����Ͻðڽ��ϱ�? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y' && slayer_count < slayer_limit) {
		std::string target_name;
		std::cout << "�����ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		std::cin >> target_name;
		bird_list->Kill(target_name);
		std::cout << "��ü �޽���: " << target_name << "��(��) ������ ���ش��Ͽ����ϴ�.." << std::endl;
		slayer_count++;
		killed = true;
	}
	else if (choice == 'Y') {
		std::cout << "����� ���� ������ �������� Ƚ���� �����߽��ϴ�." << std::endl;
	}
}