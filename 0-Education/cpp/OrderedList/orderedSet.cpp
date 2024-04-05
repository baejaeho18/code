#include "orderedSet.h"
#include <limits>
#include <iostream>

void add(OrderedSet* ordered, int v) {
	if (contains(ordered, v))
		return;

	Node* node = new Node;
	node->element = v;
	node->next = nullptr;

	Node* crnt = ordered->head;
	if (crnt == nullptr) {
		ordered->head = node;
		ordered->m_size++;
	}
	else if (v < crnt->element) {
		node->next = crnt;
		ordered->head = node;
		ordered->m_size++;
	}
	else {
		for (; crnt->next != nullptr; crnt = crnt->next) {
			if (v < crnt->next->element) {
				node->next = crnt->next;
				crnt->next = node;
				ordered->m_size++;
				return;
			}
		}
		crnt->next = node;
		ordered->m_size++;
	}
}

void add(OrderedSet* ordered, const int* arr, int size) {
	for (int i = 0; i < size; i++) {
		add(ordered, arr[i]);
	}
}

void remove(OrderedSet* ordered, int index) {
	if (index < 0 || ordered->m_size <= index) {
		std::cout << "remove(): Out-of-index" << std::endl;
		return;
	}

	Node* crnt = ordered->head, * prev = nullptr;
	if (index == 0) {
		ordered->head = crnt->next;
	}
	else {
		for (int i = 0; i < index; i++) {
			prev = crnt;
			crnt = crnt->next;
		}
		prev->next = crnt->next;
	}
	ordered->m_size--;
}

int size(OrderedSet* ordered) {
	return ordered->m_size;
}

bool contains(OrderedSet* ordered, int v) {
	for (Node* node = ordered->head; node != nullptr; node = node->next)
		if (node->element == v)
			return true;
	return false;
}

int getValue(OrderedSet* ordered, int idx) {
	if (idx < 0 || ordered->m_size <= idx)
		return std::numeric_limits<int>::min();

	Node* result = ordered->head;
	for (int i = 0; i < idx; i++) {
		result = result->next;
	}
	return result->element;
}