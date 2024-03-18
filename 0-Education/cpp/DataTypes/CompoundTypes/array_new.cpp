#include <iostream>

int main()
{
	using namespace std;

	double* p3 = new double[3];	// space for 3 doubles
	p3[0] = 0.2;				// treat p3 like an array name
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[0] is " << p3[0] << " and ";
	cout << "p3[1] is " << p3[1] << " and ";
	cout << "p3[2] is " << p3[2] << ".\n";
	p3 = p3 + 1;				// increment the pointer
	cout << "Now p3[0] is " << p3[0] << " and ";
	cout << "p3[1] is " << p3[1] << " and ";
	cout << "p3[2] is " << p3[2] << ".\n";
	p3 = p3 - 1;				// point back to beginning
	
	delete[] p3;				// free the memory

	return 0;
}

/*
* p3[0] is 0.2 and p3[1] is 0.5 and p3[2] is 0.8.
* Now p3[0] is 0.5 and p3[1] is 0.8 and p3[2] is 2.10535e-314.
*/