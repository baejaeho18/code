#pragma once
#include "BirdNode.h"
#include <string>
#include <iostream>

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

	void showList();
};

