#include <iostream>


enum spectrum { red, orange, yellow, green, blue, violet, indigo, ultraviolet = 4 };

int main()
{
	using namespace std;

	// Use enumeration name to declare a variable of enumeration type
	spectrum band;
	band = blue;		// valid, blue is an enumerator of spectrum
	//band = 2000;		// invalid, 2000 not and enumerator
	//++band;			// invalid
	//band = blue + red;// invalid
	int color = blue;	// valid, spectrum type promoted to int
	cout << "blue assigned " << color << " constant\n";
	color = 3 + red;	// valid, red converted to (int)0
	cout << "color assigned " << spectrum(color) << " constant\n";

	// You can use enumerators as symbolic constants
	// Subsequent uninitalized enumerators are larger by one than their predecessors
	enum bigstep { first, second = 100, third };
	cout << "big step has " << int(first) << ", "
		<< (int)second << ", " << int(third) << endl;

	// Can create more than one enumerator with the same value
	enum smallnums { zero, null = 0, the_one, numero_uno = 1 };
	cout << "smallnums has " << int(zero) << ", " << (int)null
		<< ", " << int(the_one) << ", " << int(numero_uno) << endl;

	return 0;
}

/*
* blue assigned 4 constant
* color assigned 3 constant
* big step has 0, 100, 101
* smallnums has 0, 0, 1, 1
*/