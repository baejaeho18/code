#pragma once
#include <string>
#include "BirdNode.h"

class BirdList
{
private:
	BirdNode* head;
	BirdNode* tail;
	int num_dead;
public:
	BirdList();
	~BirdList();

	BirdNode* GetHead() const;
	BirdNode* GetTail() const;
	BirdNode* GetBirdNodeAsName(const std::string& name);
	void IncreaseNumDead();
	int GetNumDead() const;
	void AddBirdNodeAsVoteOrder(BirdNode*);
	void AddBirdNodeAsRoleOrder(BirdNode*);

	void UseSkills();
	//void DoVotes();
	void Kill(const std::string& name);
	void Kills(BirdList*);
	void ResetKilled();
	bool IsRoleCorrect(const std::string& name, BirdRoleCode role);

	void showList();
};

