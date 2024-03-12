#include <iostream>

using namespace std;

double eval_area(double radius);

int main()
{
	double radius = 5.0;
	double area = eval_area(radius);
	cout << "Area is " << area << endl << endl;
#define	PI	3.14


	int num_wheels;
	int num_cars = 5;
	int num_bicycle = 3;
#define NUM_WHEELS_PER_CAR	(2+2)	// if 2+2, output will be 5*2+2=12
	cout << "Number of wheels of car is " << NUM_WHEELS_PER_CAR * num_cars << "." << endl << endl;	// 5*(2+2)
	
	int input;
	cout << "Enter the number of wheels per bicycle: ";
	cin >> input;
	const int Num_wheels_per_bicycle = input;		// Allows 1)explict type, 2)limit the scope, 3) create in the runtime
	cout << "Number of wheels of bicycle is " << Num_wheels_per_bicycle * num_bicycle << "." << endl << endl;

	return 0;
}

double eval_area(double radius) {
	return PI * radius * radius;	// constant PI can be used in whole file
}