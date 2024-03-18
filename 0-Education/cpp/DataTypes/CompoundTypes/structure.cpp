#include <iostream>

struct inflatable	// structure declaration - generally used
{
	char name[20];
	float volumn;
	double price;
};

// can combine the definition of a structure form and variable
struct perks
{
	int key_numbers;
	char car[12];
} mr_smith, ms_jones;

// even can initialize a variable	
struct perk
{
	int key_numbers;
	char car[12];
} mr_glitz = {
	7, "Packard"
};

// Also, can create a structure with no type name
struct		// no tag
{
	int x;	// 2 members
	int y;
} position;	// a structure variable

int main() {
	using namespace std;

	inflatable guest = {
		"Glorious Gloria",	// name value
		1.88,				// volumn value
		29.99				// price value
	};	// guest is a stucture variable of type inflatable
	inflatable pal = { "Audacious Arthur", 3.12, 32.99 };

	cout << "Expand your guest list with " << guest.name
		<< " and " << pal.name << "!\n";
	// Each member can be accessed using the membership operator(.)
	cout << "You can have both for $"
		<< guest.price + pal.price << "!\n";

	// Can use the assignment operator to copy each member even including arrays
	inflatable choice;
	choice = pal;	
	cout << "choice: " << choice.name << " for $" << choice.price << endl;
	// but copy specific array member is impossible
	// choice.name = guest.name;	// invalid

	// it's also possible to create arrays whose elements are structures
	inflatable guests[5] = {
		guest,
		pal,
		choice,
		{"Bambi", 0.5, 21.99},
		{"Godzilla", 2000, 565.99}
	};
	cout << "The guests " << guests[0].name << " and " << guests[1].name
		<< "\nhave a combined volume of "
		<< guests[0].volumn + guests[1].volumn << " cubic feet.\n";
	cout << "The guests name's first characters are "
		<< guests[0].name[0] << ", " << guests[1].name[0] << ", "
		<< guests[2].name[0] << ", " << guests[3].name[0] << ", "
		<< guests[4].name[0] << ".\n";

	return 0;
}

/*
* Expand your guest list with Glorious Gloria and Audacious Arthur!
* You can have both for $62.98!
* choice: Audacious Arthur for $32.99
* The guests Glorious Gloria and Audacious Arthur
* have a combined volume of 5 cubic feet.
* The guests name's first characters are G, A, A, B, G.
*/