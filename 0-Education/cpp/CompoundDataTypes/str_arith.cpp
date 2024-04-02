#include <iostream>
#include <string>		// make string class available
#include <cstring>		// C-style string library

#pragma warning(disable : 4996)

int main()
{
	using namespace std;	// if namespace is in a block, it only works in there

	char charr1[20];
	char charr2[20];
	string str1;
	string str2;

	// finding the lengh of a string object and a C-style string
	cout << "Length of string in charr before input: "
		<< strlen(charr1) << endl;
	cout << "Length of string in str before input: "
		<< str1.size() << endl;

	cout << "Enter a line of text:\n";
	cin.getline(charr1, 20);
	cout << "You entered: " << charr1 << endl;

	// assignment for string objects and character array
	str1 = charr1;			// copy charr1 to str1
	str2 = str1;			// copy str1 to str2
	strcpy(charr2, charr1);	// copy charr1 to charr2

	// appending for string objects and character arrays
	str2 += str1;			// add str1 to end of str2
	strcat(charr2, charr1);	// add charr1 to end of charr2

	cout << "The charr " << charr2 << " contains "
		<< strlen(charr2) << " characters.\n";
	cout << "The string " << str2 << " contains "
		<< str2.size() << " characters.\n";

	return 0;
}

/*
* Length of string in charr before input: 102
* Length of string in str before input: 0
* Enter a line of text:
* house
* You entered: house
* The charr househouse contains 10 characters.
* The string househouse contains 10 characters.
*/