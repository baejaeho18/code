#include <iostream>

using namespace std;

int main()
{
	int decimal = 42;		// 십진수
	int hexadecimal = 0x42;	// 16진수 (prefix : 0x)
	int octal = 042;		// 8진수  (prefix : 0)

	cout << "Integer Literals of 42: " << endl;
	cout << "decimal     = " << decimal << " (42 in decimal)" << endl;
	cout << "hexadecimal = " << hexadecimal << " (0x42 in hex : 16*4+2)" << endl;
	cout << "octal       = " << octal << " (042 in octal : 8*4+2)" << endl << endl;

	cout << "decimal     = " << decimal << " (decimal for 42)" << endl;
	cout << hex;	// manipulator for changing number base
	cout << "hexadecimal = " << decimal << " (hexadecimal for 42 : 16*2+10)" << endl;
	cout << oct;	// doesn't display anything onscreen itself
	cout << "octal       = " << decimal << " (octal for 42 : 8*5+2)" << endl;

	return 0;
}