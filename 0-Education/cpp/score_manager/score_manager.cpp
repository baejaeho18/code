#include <iostream>
#include <iomanip>

#include "menu.h"

int main() {

	student students[100];	// 최대 학생수: 100
	int student_number = 0;		// 실제 학생수

	int selection;
	while (1) {
		show_menu();
		cin >> selection;

		if (selection == 1) {
			if (add_student(&students[student_number++]) > 0)
				cout << "The student is added!" << endl;
			else
				student_number--;
		}
		else if (selection == 2 && edit_score(students, student_number) > 0) {
			cout << "Score editing done!" << endl;
		}
		else if (selection == 3) {
			print_score_average(students, student_number);
		}
		else if (selection == 4) {
			print_score_list(students, student_number);
			cout << "Finished printing the list!\n";
		}
		else if (selection == 5) {
			print_grade_list(students, student_number);
			cout << "Finished printing the list!\n";
		}
		else if (selection == 6) {
			cout << "Good Bye!" << endl;
			break;
		}
		else {
			cout << "You Entered Wrong Menu Number!" << endl;
		}
	}
	return 0;
}