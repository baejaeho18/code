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
	std::cout << player_name << "님 투표를 하시겠습니까? [Y/N]: ";
	std::cin >> choice;
	if (choice == 'Y') {
		std::string target_name;
		std::cout << "투표하고 싶은 플레이어의 이름을 입력하세요: ";
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
