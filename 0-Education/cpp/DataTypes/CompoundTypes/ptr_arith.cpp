#include <iostream>

int main()
{
	using namespace std;

	// ptr is a pointer to char, while e is a char variable
	int* ptr1 = (int*)100;
	int n1 = 10, m1 = 5;
	ptr1 = ptr1 + n1; // ptr = 100 + sizeof(int) * n (4*n bytes) -> 140
	cout << ptr1 << endl;
	ptr1 = ptr1 - m1; // ptr = ptr - sizeof(int) * m (4*m bytes) -> 120
	cout << ptr1 << endl;

	double* ptr2 = (double*)100;
	int n2 = 10, m2 = 5;
	ptr2 = ptr2 + n2; // ptr = 100 + sizeof(double) * n (8*n bytes) -> 180
	cout << ptr2 << endl;
	ptr2 = ptr2 - m2; // ptr = ptr - sizeof(double) * m (8*m bytes) -> 140
	cout << ptr2 << endl << endl;


	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3, 2, 1 };
	// Two ways to get the address of an array
	double* pw = wages;		// name of an array = address
	short* ps = &stacks[0];	// or use address operator
	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "add 1 to the pw pointer:\n";
	cout << "pw = " << pw << ", *pw = " << *pw << endl << endl;

	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "add 1 to the ps pointer:\n";
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

	cout << "access two elements with array notation\n";
	cout << "stacks[0] = " << stacks[0]
		<< ", stacks[1] = " << stacks[1] << endl;
	cout << "access two elements with pointer notation\n";
	cout << "*stacks = " << *stacks
		<< ", *(stacks + 1) =  " << *(stacks + 1) << endl;
	// arrayname[i] == *(arrayname + i)
	// pointername[i] == *(pointername + i)

	cout << sizeof(wages) << " = size of wages array\n";
	cout << sizeof(pw) << " = size of pw pointer\n\n";

	// Pointer Arithmetic
	int tacos[10] = { 5,2,8,4,1,2,2,4,6,8 };
	int* pt = tacos;	// suppose pt and tacos are the address 3000
	pt = pt + 1;		// now pt is 3004, if a int is 4 byte
	int* pe = &tacos[9];// pe is 3036
	pe = pe - 1;		// now pe is 3032
	int diff = pe - pt;	// diff is 7, the speration between tacos[8] and tacos[1]
	cout << diff << endl;

	return 0;
}

/*
* 000000000000008C
* 0000000000000078
* 00000000000000B4
* 000000000000008C
* 
* pw = 00000098102FFA18, *pw = 10000
* add 1 to the pw pointer:
* pw = 00000098102FFA20, *pw = 20000
*
* ps = 00000098102FFA44, *ps = 3
* add 1 to the ps pointer:
* ps = 00000098102FFA46, *ps = 2
*
* access two elements with array notation
* stacks[0] = 3, stacks[1] = 2
* access two elements with pointer notation
* *stacks = 3, *(stacks + 1) =  2
* 24 = size of wages array
* 8 = size of pw pointer
* 
* 7
*/