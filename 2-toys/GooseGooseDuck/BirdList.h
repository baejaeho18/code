#pragma once
#include <string>
#include "BirdNode.h"

class BirdList
{
private:
	BirdNode* head;
	BirdNode* tail;
public:
	BirdList();
	~BirdList();

	BirdNode* GetHead() const;
	BirdNode* GetTail() const;
	void AddBirdNodeAsVoteOrder(BirdNode*);
	void AddBirdNodeAsRoleOrder(BirdNode*);
	void UseSkills();
	//void DoVotes();
	void Kill(const std::string& name);
	bool existNode(const std::string& name, BirdRoleCode role);

	void showList();
};

