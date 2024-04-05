#ifndef SET__
#define SET__


struct Node {
	int element;
	Node* next;
};

struct OrderedSet {
	int m_size;
	Node* head;
};

void add(OrderedSet* ordered, int v);
void add(OrderedSet* ordered, const int* arr, int size);
void remove(OrderedSet* ordered, int index);
int size(OrderedSet* ordered);
bool contains(OrderedSet* ordered, int v);
int getValue(OrderedSet* ordered, int idx);

#endif SET__