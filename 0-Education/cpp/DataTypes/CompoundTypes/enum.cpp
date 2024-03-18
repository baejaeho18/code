#include <iostream>

enum spectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolet};

int main()
{
	using namespace std;
	// Use enumeration name to declare a variable of enumeration type
	spectrum band;
	band = blue;		// valid, blue is an enumerator of spectrum
	//band = 2000;		// invalid, 2000 not and enumerator
	//++band;			// invalid
	//band = blue + red;// invalid
	int b = blue;
	cout << "blue assigned " << b << " constant\n";

	// You can use enumerators as symbolic constants
	enum bits { one = 1, two = 2, four = 4, eight = 8, fifth};
	int v = two;
	int w = fifth;

	cout << "two assigned " << v << " constant\n"
		<< "fifth assigned " << w << " consant!\n";

	return 0;
}

/*
* blue assigned 4 constant
* two assigned 2 constant
* fifth assigned 9 consant!
*/