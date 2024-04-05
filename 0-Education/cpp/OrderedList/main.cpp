#include "orderedList.h"
#include <iostream>

void simpleTest1(OrderedSet* o) {
	add(o, 5);
	add(o, 4);
	add(o, 3);
	add(o, 80);
	add(o, 50);

	for (int i = 0; i < o->m_size; ++i) {
		std::cout << getValue(o, i) << ", ";
	}
	std::cout << std::endl;
}

void simpleTest2(OrderedSet* o) {
	int vals[] = { 10, 20, 35, 35, 10 };
	add(o, vals, sizeof(vals) / sizeof(int));

	for (int i = 0; i < o->m_size; ++i) {
		std::cout << getValue(o, i) << ", ";
	}
	std::cout << std::endl;
}

void simpleTest3(OrderedSet* o) {
	remove(o, 3);

	for (int i = 0; i < o->m_size; ++i) {
		std::cout << getValue(o, i) << ", ";
	}
	std::cout << std::endl;
}

void simpleTest4(OrderedSet* o) {
	std::cout << std::boolalpha << contains(o, 20) << std::endl;
	std::cout << std::boolalpha << contains(o, 40) << std::endl;
}

void simpleTest5(OrderedSet* o) {
	std::cout << size(o) << std::endl;
}

void simpleTest6(OrderedSet* o) {
	remove(o, 0);

	for (int i = 0; i < o->m_size + 1; ++i) {
		std::cout << getValue(o, i) << ", ";
	}
	std::cout << std::endl;
}

void simpleTest7(OrderedSet* o) {
	int vals[] = { 90, 0, 2, 7, -1 };
	add(o, vals, sizeof(vals) / sizeof(int));

	for (int i = -1; i < o->m_size + 1; ++i) {
		std::cout << getValue(o, i) << ", ";
	}
	std::cout << std::endl;
}

void simpleTest8(OrderedSet* o) {
	remove(o, 13);
	remove(o, -1);
	remove(o, 12);

	for (int i = 0; i < o->m_size; ++i) {
		std::cout << getValue(o, i) << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	OrderedSet* orderedList = new OrderedSet;
	orderedList->head = nullptr;
	orderedList->m_size = 0;

	std::cout << "<<Simple Test 1>>" << std::endl;
	simpleTest1(orderedList);
	std::cout << "<<Simple Test 2>>" << std::endl;
	simpleTest2(orderedList);
	std::cout << "<<Simple Test 3>>" << std::endl;
	simpleTest3(orderedList);
	std::cout << "<<Simple Test 4>>" << std::endl;
	simpleTest4(orderedList);
	std::cout << "<<Simple Test 5>>" << std::endl;
	simpleTest5(orderedList);

	std::cout << "<<Simple Test 6>>" << std::endl;
	simpleTest6(orderedList);
	std::cout << "<<Simple Test 7>>" << std::endl;
	simpleTest7(orderedList);
	std::cout << "<<Simple Test 8>>" << std::endl;
	simpleTest8(orderedList);

	return 0;
}
