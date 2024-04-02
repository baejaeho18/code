#include <iostream>

using namespace std;

int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree(31);			// int converted to float
	int guess (3.9832);		// double converted to int
	int debt = 7.2E12;		// result not defined in C++, too large number

	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl << endl;		// display wrong number, 1.6E09

	int auks, bats, coots;
	// the following statement adds the values as double,
	// then converts the results to int
	auks = 19.99 + 11.99;
	// these statements add values as int
	bats = (int)19.99 + (int) 11.99; // old C syntax
	coots = int(19.99) + int (11.99); // new C++ syntax
	cout << "auks = " << auks << ", bats = " << bats
		 << ", coots = " << coots << endl;

	char ch = 'Z';
	cout << "The code for " << ch << " is "; // print as char
	cout << int(ch) << endl;

	return 0;
}