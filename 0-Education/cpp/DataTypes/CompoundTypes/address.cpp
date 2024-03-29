#include <iostream>

using namespace std;

int main()
{
	// The address of the variable : &
	int donuts = 6;
	double cups = 4.5;
	cout << "donuts value = " << donuts;
	cout << " and donuts address = " << &donuts << endl;
	cout << "cups value = " << cups;
	cout << " and cups address = " << &cups << endl << endl;

	// Dereferencing Operator(*): indicates the value at the location stored in pointer
	int val;
	int* ptr = &val;	// pointer to integer initialized to &val
	*ptr = 100;			// equivalent to val = 100;
	cout << "*ptr(" << *ptr << ") == val(" << val << ")" << endl;
	val = 500;
	cout << "*ptr(" << *ptr << ") == val(" << val << ")" << endl << endl;

	// Pointer Arithmetics
	int updates = 6;		// declare a variable
	int* p_updates;			// declare a pointer to an int
	p_updates = &updates;	// assign address of int to pointer
	cout << "Values: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;

	cout << "Addresses: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;

	*p_updates = *p_updates + 1;	// 
	cout << "Now updates = " << updates << " and &updates = " << &updates << endl;
	cout << "Now *p_updates = " << *p_updates << " and p_updates = " << p_updates << endl;

	p_updates += 1;
	cout << "Now updates = " << updates << " and &updates = " << &updates << endl;
	cout << "Now *p_updates = " << *p_updates << " and p_updates = " << p_updates << endl << endl;


	// Sizeof Pointers
	cout << sizeof(char) << ", " << sizeof(char*) << endl;
	cout << sizeof(int) << ", " << sizeof(int*) << endl;
	cout << sizeof(double) << ", " << sizeof(double*) << endl;

	//char* ptr, e;	// ptr is a pointer to char, while e is a char variable
	int* ptr1 = (int*)100;
	int n1 = 10, m1 = 5;
	ptr1 = ptr1 + n1; // ptr = 100 + sizeof(int) * n (4*n bytes) -> 140
	ptr1 = ptr1 - m1; // ptr = ptr - sizeof(int) * m (4*m bytes) -> 120

	double* ptr2 = (double*)100;
	int n2 = 10, m2 = 5;
	ptr2 = ptr2 + n2; // ptr = 100 + sizeof(double) * n (8*n bytes) -> 180
	ptr2 = ptr2 - m2; // ptr = ptr - sizeof(double) * m (8*m bytes) -> 140


	return 0;
}

/*
* donuts value = 6 and donuts address = 0000005DADAFF4B4
* cups value = 4.5 and cups address = 0000005DADAFF4D8
*
* *ptr(100) == val(100)
* *ptr(500) == val(500)
*
* Values: updates = 6, *p_updates = 6
* Addresses: &updates = 0000005DADAFF534, p_updates = 0000005DADAFF534
* Now updates = 7 and &updates = 0000005DADAFF534
* Now *p_updates = 7 and p_updates = 0000005DADAFF534
* Now updates = 7 and &updates = 0000005DADAFF534
* Now *p_updates = -858993460 and p_updates = 0000005DADAFF538
*
* 1, 8
* 4, 8
* 8, 8
*/