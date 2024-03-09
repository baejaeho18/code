#include <iostream>

using namespace std;

int main()
{
	// floating-point types
	cout.setf(ios_base::fixed, ios_base::floatfield);	// fixed-point
	float tub = 10.0 / 3.0;
	double mint = 10.0 / 3.0;
	const float Million = 1.0e6;

	cout << "tub = " << tub;
	cout << ", a million tubs = " << Million * tub;
	cout << ", \nand ten million tubs = ";
	cout << 10 * Million * tub << endl;

	cout << "mint = " << mint << " and a million mint = ";
	cout << Million * mint << endl;


	// Arithmetic
	float a = 2.34e+22f;	// equalls to 2.34E22
	float b = a + 1.f;		// equalls to 1.0f

	cout << "a = " << a << endl;
	cout << "b - a = " << b - a << endl;

	// integer and floating-point division
	cout << "Integer division: 9/5 = " << 9 / 5 << endl;
	cout << "Floating-point division: 9.0/5.0 = ";
	cout << 9.0 / 5.0 << endl;
	cout << "Mixed division: 9.0/5 = " << 9.0 / 5 << endl;
	cout << "double Constants: 1e7/9.0 = ";
	cout << 1.e7 / 9.0 << endl;
	cout << "float constatns: 1e7f/9.0f = ";
	cout << 1.e7f / 9.f << endl;

	return 0;
}