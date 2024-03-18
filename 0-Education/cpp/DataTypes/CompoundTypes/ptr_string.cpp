#include <iostream>
#include <cstring>		// declare strlen(), strcpt()

#pragma warning(disable : 4996)

int main()
{
	using namespace std;

	char animal[5] = "bear";	// animal holds 'bear\0'
	// animal = "bear";			// invalid!
	char* str = animal;			// str points to the 1st element of animal
	cout << animal[0] << *(animal + 1);
	cout << *(str + 2) << str[3] << endl;
	str[1] = '\0';				// equivalent to animal[1] = '\0'
	cout << str << endl;
	*(animal + 1) = 'e';		// equivalent to animal[1] = 'e'
	cout << animal << endl << endl;

	str = animal;		// set str to point to string
	cout << "Using assignment operator(=): \n";
	cout << animal << " at " << (int*)animal << endl;
	cout << str << " at " << (int*)str << endl;

	str = new char[strlen(animal) + 1];	// get new storage
	strcpy(str, animal);				// copy string to new storage
	cout << "Using strcpy() function: \n";
	cout << animal << " at " << (int*)animal << endl;
	cout << str << " at " << (int*)str << endl;

	delete[] str;

	return 0;
}

/*
* bear
* b
* bear
*
* Using assignment operator(=):
* bear at 000000692CDCF4C4
* bear at 000000692CDCF4C4
* Using strcpy() function:
* bear at 000000692CDCF4C4
* bear at 000001EC48434140
*/