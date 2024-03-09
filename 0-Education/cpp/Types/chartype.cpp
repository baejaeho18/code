#include <iostream>

using namespace std;

int main()
{
	char ch;

	cout << "Enter a character: " << endl;
	cin >> ch;
	cout << "Hola! ";
	cout << "Thank you for the " << ch << " character." << endl;

	int i = ch;
	cout << "The ASCII code for " << ch << " is " << i << endl;		
	// While both ch and i have same vinteger value, cout prints them differenty!

	cout << "Add one to the character code: " << endl;
	ch = ch + 1;		// As char is a 1-byte integer, you can apply integer operations
	i = ch;
	cout << "The ASCII code for " << ch << " is " << i << endl;

	// using the cout.put() member function to display a char
	cout << "Displaying char ch using cout.put(ch): ";
	cout.put(ch);
	cout.put((int)ch);
	cout.put(i);
	cout.put(char(i));
	// cout is an object of oustream class.
	// .(point) is a membership operator
	// cout.put() is a member function which displays a single character
	cout.put('!');		// using cout.put() to display a char constant
	cout << endl 
		 << "Done" << endl;

	//for (int t = 0; t < 128; t++)
	//	cout.put(t);

	return 0;
}

/*
* Output of chartype.cpp
* Enter a character:
* M
* Hola! Thank you for the M character.
* The ASCII code for M is 77
* Add one to the character code:
* The ASCII code for N is 78
* Displaying char ch using cout.put(ch): NNNN!
* Done
*/