#include "BirdList.h"
#include "Bird.h"
#include "Duck.h"
#include "Falcon.h"

BirdList::BirdList() {
	this->head = NULL;
	this->tail = NULL;
	num_dead = 0;
	num_birds_alive = num_duck_alive = num_goose_alive = 0;
	absentation_vote = 0;
	isDodoWin = false;
}

BirdList::~BirdList() {
	BirdNode* current = head;
	while (current != NULL) {
		BirdNode* next = current->GetNext();
		current->~BirdNode();
		current = next;
	}
	delete this->head;
	delete this->tail;
}

int BirdList::GetNumDead() const {
	return num_dead;
}

BirdNode* BirdList::GetHead() const {
	return this->head;
}

BirdNode* BirdList::GetTail() const {
	return this->tail;
}


BirdNode* BirdList::GetBirdNodeAsName(const std::string& name) {
	BirdNode* current = head;
	while (current != nullptr) {
		if (current->GetBird()->GetPlayerName() == name)
			return current;
		current = current->GetNext();
	}
}

void BirdList::AddBirdNodeAsVoteOrder(BirdNode* node) {
	if (head == NULL) {
		tail = head = node;
	}
	else {
		tail->SetNext(node);
		tail = node;
	}
}

void BirdList::AddBirdNodeAsRoleOrder(BirdNode* node) {
	if (head == NULL) {
		tail = head = node;
		return;
	}
	
	BirdNode* current = head;
	BirdNode* previous = nullptr;

	while (current != nullptr && current->GetBird()->GetRoleCode() <= node->GetBird()->GetRoleCode()) {
		previous = current;
		current = current->GetNext();
	}

	if (previous == nullptr) {
		node->SetNext(head);
		head = node;
	}
	else {
		previous->SetNext(node);
		node->SetNext(current);
		if (current == nullptr) {
			tail = node;
		}
	}

	if (node->GetBird()->GetRoleCode() == BirdRoleCode::kAssassinDuck || node->GetBird()->GetRoleCode() == BirdRoleCode::kDuck)
		num_duck_alive++;
	if (node->GetBird()->GetRoleCode() == BirdRoleCode::kDetectiveGoose ||
		node->GetBird()->GetRoleCode() == BirdRoleCode::kMorticianGoose ||
		node->GetBird()->GetRoleCode() == BirdRoleCode::kGoose)
		num_goose_alive++;
	num_birds_alive++;
}

void BirdList::UseSkills() {
	BirdNode* current = head;
	while (current != nullptr) {
		if (!current->GetBird()->GetIsDead())
			current->GetBird()->Skill(this);
		current = current->GetNext();
	}
}

void BirdList::Kill(const std::string& name) {
	BirdNode* current = head;
	while (current != nullptr) {
		if (current->GetBird()->GetPlayerName() == name) {
			current->GetBird()->SetDead();
			num_dead++;
			num_birds_alive--;
			if (current->GetBird()->GetRoleCode() == BirdRoleCode::kAssassinDuck || current->GetBird()->GetRoleCode() == BirdRoleCode::kDuck)
				num_duck_alive--;
			if (current->GetBird()->GetRoleCode() == BirdRoleCode::kDetectiveGoose ||
				current->GetBird()->GetRoleCode() == BirdRoleCode::kMorticianGoose ||
				current->GetBird()->GetRoleCode() == BirdRoleCode::kGoose)
				num_goose_alive--;
			return;
		}
		current = current->GetNext();
	}
}

// 한 list에서 죽은 bird들을 다른 list에서도 죽은 것으로 처리	// vote에서도 increasNumDead() 호출해야 함
void BirdList::Kills(BirdList* bird_list) {
	if (num_dead <= 0)
		return;

	BirdNode* current = bird_list->GetHead();
	while (current != nullptr || 0 < num_dead) {
		Bird* current_bird = current->GetBird();
		if (current_bird->GetIsDead()) {
			this->Kill(current_bird->GetPlayerName());
			num_dead--;
		}
		current = current->GetNext();
	}
}

bool BirdList::IsRoleCorrect(const std::string& name, BirdRoleCode code) {
	BirdNode* current = head;
	while (current != nullptr) {
		if (current->GetBird()->GetPlayerName() == name &&
			current->GetBird()->GetRoleCode() == code)
			return true;
		current = current->GetNext();
	}
	return false;
}

void BirdList::ResetKilled() {
	BirdNode* current = head; 
	while (current != nullptr) {
		current->GetBird()->ResetKilled();
		//Bird* current_bird = current->GetBird();
		//if (current_bird != nullptr) {
		//	if (Duck* duck = dynamic_cast<Duck*>(current_bird))
		//		duck->ResetKilled();
		//	else if (Falcon* falcon = dynamic_cast<Falcon*>(current_bird))
		//		falcon->ResetKilled();
		//}
		current = current->GetNext();
	}
}

bool BirdList::isEmpty() {
	return (num_birds_alive == 0);
}

void BirdList::DoVotes() {
	BirdNode* current = head;
	while (current != nullptr) {
		if (!current->GetBird()->GetIsDead())
			current->GetBird()->Vote(this);
		current = current->GetNext();
	}
	// Who will be out?
	current = head;
	int max_voted = 0;
	int sec_max_voted = 0;
	Bird* max_voted_bird;
	while (current != nullptr) {
		if (!current->GetBird()->GetIsDead())
			if (max_voted <= current->GetBird()->GetVoted()) {
				max_voted_bird = current->GetBird();
				sec_max_voted = max_voted;
				max_voted = current->GetBird()->GetVoted();
			}
		current = current->GetNext();
	}
	if (max_voted <= absentation_vote) {
		sec_max_voted = max_voted;
		max_voted = absentation_vote;
	}
	if (max_voted != sec_max_voted) {
		max_voted_bird->SetDead();
		if (max_voted_bird->GetRoleCode() == BirdRoleCode::kDodoBird)
			isDodoWin = true;
		std::cout << "전체 메시지: [" << max_voted_bird->GetPlayerName() << "[은(는) 더 좋은 곳을 갔습니다." << std::endl;
		if (max_voted_bird->GetRoleCode() == BirdRoleCode::kAssassinDuck ||
			max_voted_bird->GetRoleCode() == BirdRoleCode::kDuck)
			std::cout << "전체 메시지: 만세 [" << max_voted_bird->GetPlayerName() << "]은(는) 오리입니다!!" << std::endl;
		else
			std::cout << "전체 메시지: 맙소사 [" << max_voted_bird->GetPlayerName() << "]은(는) 오리가 아닙니다!!" << std::endl;
	}
	else {
		std::cout << "전체 메시지: 이번 투표에서는 아무 조류도 당첨되지 않았습니다." << std::endl;
	}
}

void BirdList::ResetAbsentationVote() {
	absentation_vote = 0;
}

void BirdList::DoAbsentationVote() {
	absentation_vote++;
}

bool BirdList::GetIsDodoWin() {
	return isDodoWin;
}

void BirdList::ResetIsDodoWin() {
	isDodoWin = false;
}


int BirdList::GetNumAliveBird() {
	return num_birds_alive;
}
int BirdList::GetNumAliveGoose() {
	return num_goose_alive;
}
int BirdList::GetNumAliveDuck() {
	return num_duck_alive;
}
bool BirdList::IsFalconAlive() {
	return is_falcon_alive;
}

// for test
void BirdList::showList() {
	BirdNode* current = head;
	while (current != nullptr) {
		std::cout << "name:" << current->GetBird()->GetPlayerName()
			<< " code:" << static_cast<int>(current->GetBird()->GetRoleCode()) << std::endl;
		current = current->GetNext();
	}
}

void BirdList::DeleteDeadBird() {
	BirdNode* current = head;
	while (current != nullptr) {

	}
}