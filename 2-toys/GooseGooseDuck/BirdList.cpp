#include "BirdList.h"

#include "Bird.h"

BirdList::BirdList() {
	this->head = NULL;
	this->tail = NULL;
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

BirdNode* BirdList::GetHead() const {
	return this->head;
}

BirdNode* BirdList::GetTail() const {
	return this->tail;
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
}