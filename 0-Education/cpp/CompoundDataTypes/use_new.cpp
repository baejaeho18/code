#include <iostream>

int main()
{
	using namespace std;

	int nights = 1001;
	int* pt = new int;		// allocate space for an int
	*pt = 1001;				// store a value there
	cout << "nights value = " << nights << ": location " << &nights << endl;
	cout << "int value = " << *pt << ": location = " << pt << endl;

	double* pd = new double;	// allocate space for a double
	*pd = 10000001.0;			// store a double there
	cout << "double value = " << *pd << ": location = " << pd << endl;
	cout << "location of pointer pd: " << &pd << endl;
	// Both pt and pt are pointers, so they have the same size, while *pt and *pd have different size
	cout << "size of pt = " << sizeof(pt) << ": size of *pt = " << sizeof(*pt) << endl;
	cout << "size of pd = " << sizeof(pd) << ": size of *pd = " << sizeof(*pd) << endl;

	delete pt, pd;	// Must deallocate memory with delet when done
	return 0;
}

/*
* nights value = 1001: location 0000003D630FFB64
* int value = 1001: location = 000001A5C9C56F50
* double value = 1e+07: location = 000001A5C9C64360
* location of pointer pd: 0000003D630FFBA8
* size of pt = 8: size of *pt = 4
* size of pd = 8: size of *pd = 8
*/