#pragma once
#include <string>
#include "BirdNode.h"

class BirdList
{
private:
	BirdNode* head;
	BirdNode* tail;
	int num_dead;

	int num_birds_alive;
	int num_goose_alive;
	int num_duck_alive;
public:
	BirdList();
	~BirdList();

	BirdNode* GetHead() const;
	BirdNode* GetTail() const;
	BirdNode* GetBirdNodeAsName(const std::string& name);
	int GetNumDead() const;
	void AddBirdNodeAsVoteOrder(BirdNode*);
	void AddBirdNodeAsRoleOrder(BirdNode*);

	void UseSkills();
	void DoVotes();
	void Kill(const std::string& name);
	void Kills(BirdList*);
	void ResetKilled();
	bool IsRoleCorrect(const std::string& name, BirdRoleCode role);
	bool isEmpty();
	void VoteTo(const std::string& name);

	void showList();
};

