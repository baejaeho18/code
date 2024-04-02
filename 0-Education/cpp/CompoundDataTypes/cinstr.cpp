#include <iostream>

using namespace std;

int main()
{
	const int Arsize = 20;
	char name[Arsize];
	char desert[Arsize];


	cout << "----- using cin.getline()" << endl;
	cout << "Enter your name:\n";
	cin.getline(name, Arsize);
	cout << "Enter your favorite desert:\n";
	cin.getline(desert, Arsize);
	cout << "I hava some delicous " << desert
		<< " for you, " << name << ".\n";
	// Input Queue: 'Dirk Hammernose', new-line, 'Radish Torte', new-line

	cout << "----- using cin" << endl;
	cout << "Enter your name:\n";
	cin >> name;
	cout << "Enter your favorite desert:\n";
	cin >> desert;
	cout << "I hava some delicous " << desert
		<< " for you, " << name << ".\n";
	// Input Queue: 'Alisa', space(white space), 'Bread', new-line(whitespace), null character(from keyboard)

	return 0;
}

/*
* ----- using cin.getline()
* Enter your name:
* Dirk Hammernose
* Enter your favorite desert:
* Radish Torte
* I hava some delicous Radish Torte for you, Dirk Hammernose.
* ----- using cin
* Enter your name:
* Alisa Bread
* Enter your favorite desert:
* I hava some delicous Bread for you, Alisa.
*/