#ifndef SET__
#define SET__


struct Node {
	int element;
	Node* next;
};

struct OrderedList {
	int m_size;
	Node* head;
};

void add(OrderedList* ordered, int v);
void add(OrderedList* ordered, const int* arr, int size);
void remove(OrderedList* ordered, int index);
int size(OrderedList* ordered);
bool contains(OrderedList* ordered, int v);
int getValue(OrderedList* ordered, int idx);

#endif SET__