#ifndef __PROB_1__
#define __PROB_1__

struct OrderedList {
	int m_size;
	Node* head;
};

struct Node {
	int element;
	Node* next;
};

void add(OrderedList* ordered, int v);
void add(OrderedList* ordered, const int* arr, int size);
void remove(OrderedList* ordered, int index);
int size(OrderedList* ordered);
bool contains(OrderedList* ordered, int v);
int getValue(OrderedList* ordered, int idx);


#endif __PROB_1__