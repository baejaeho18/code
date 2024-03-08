#include <iostream>

using namespace std;

int main() {

	char name[100];		// 99 characters for name and 1 character for end symbol(\0)
	int birth_year;
	int std_num;
	int age;

	// Input
	// I assumed that cin doesn't need endl as like cout.
	// 1. English name
	cin >> name;
	// 2. Birth-Year and Student=Number
	cin >> birth_year >> std_num;

	// Operation : get k-age from birth_year
	// Constraint(birth_year <= 2023) means age is always bigger than 2
	age = 2024 - birth_year + 1;

	// Output
	// I assumed that no space appears between the two output which surround the '<<' operator.
	// 1. Name
	cout << "My name is " << name << "." << endl;
	// 2. age
	cout << "I am " << age << " years old." << endl;
	// 3. std_num
	cout << "My student ID is " << std_num << "." << endl;

	return 0;
}