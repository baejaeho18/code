#include "Bird.h"
#include "BirdList.h"

Bird::Bird()
	: player_name(), role_code(), isDead(false), killed(false), isVoted(0) { }
Bird::Bird(std::string name_, BirdRoleCode code_) 
	: player_name(name_), role_code(code_), isDead(false), killed(false), isVoted(0) { }
Bird::~Bird() { }

void Bird::SetDead() { 
	isDead = true; 
};

void Bird::ResetKilled() {
	killed = false;
}

bool Bird::DidKill() {
	return killed;
}

void Bird::ResetVoted() {
	isVoted = 0;
}

void Bird::Vote(BirdList* bird_list) {
	char choice;
	std::cout << player_name << "�� ��ǥ�� �Ͻðڽ��ϱ�? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y') {
		std::string target_name;
		std::cout << "��ǥ�ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		std::cin >> target_name;
		//bird_list->VoteTo(target_name);
		bird_list->GetBirdNodeAsName(target_name)->GetBird()->Voted();
	}
	else {
		bird_list->DoAbsentationVote();
	}
}

void Bird::Voted() {
	isVoted++;
}

int Bird::VotedNumber() {
	return isVoted;
}
