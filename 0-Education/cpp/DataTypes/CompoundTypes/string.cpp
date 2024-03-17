#include <iostream>
#include <cstring> // for the strlen() function

using namespace std;

int main()
{
	const int Size = 15;
	char name1[Size];				// empty array
	char name2[Size] = "C++owboy";	// initialized array
	
	cout << "Howdy!" "I'm "; 	// C++ enables you to concatenate string literals seperated only by whitespace(spaces, tabs, and newlinew)
	cout << name2 
		 << "! What's your name?\n";
	cin >> name1;
	cout << "Well, " << name1 << ", your name has ";
	cout << strlen(name1) << " letters and is stored\n";
	cout << "in an array of " << sizeof(name1) << " bytes.\n";
	cout << "Your initial is " << name1[0] << ".\n";
	name2[3] = '\0'; // set to null character which terminate quoted string
	cout << "Here are the first 3 characters of my name: ";
	cout << name2 << endl;

	return 0;
}

/*
* Howdy! I'm C++owboy! What's your name?
*  Basicman
*  Well, Basicman, your name has 8 letters and is stored
*  in an array of 15 bytes.
*  Your initial is B.
*  Here are the first 3 characters of my name: C++
*/