#include "menu.h"

void show_menu() {
	cout << "----------MENU----------\n";
	cout << "1. Add a student" << endl;
	cout << "2. Edit the score of a student" << endl;
	cout << "3. Print average score" << endl;
	cout << "4. Print scores list" << endl;
	cout << "5. Print grades list" << endl;
	cout << "6. Exit" << endl;
	cout << "------------------------\n";
	cout << "Selection: ";
}

int add_student(student* new_student) {
	if (new_student->set_id() < 0) {
		cout << "Failed to add: invalid student id!" << endl;
		return -1;
	}
	if (new_student->set_name() < 0) {
		cout << "Failed to add: invalid name!" << endl;
		return -1;
	}
	if (new_student->set_midterm_exam_scroe() < 0) {
		cout << "Failed to add: invalid midterm exam score!" << endl;
		return -1;
	}
	if (new_student->set_final_exam_score() < 0) {
		cout << "Failed to add: invalid final exam score!" << endl;
		return -1;
	}
	if (new_student->set_retake() < 0) {
		cout << "Failed to add: invalid retake value!" << endl;
		return -1;
	}
	return 1;
}

int edit_score(student students[], int student_number) {

	int selection;
	cout << "--------Function--------\n";
	cout << "1. Edit the midterm exam score\n";
	cout << "2. Edit the final exam score\n";
	cout << "------------------------\n";
	cout << "Selection: ";
	cin >> selection;

	int temp_id;
	cout << "Student id: ";
	cin >> temp_id;
	// check the id is valid
	if (temp_id < 10000000 || 100000000 <= temp_id) {
		cout << "Failed to edit: invalid student id!";
		return -1;
	}
	// find index of student by id
	int idx;
	for (idx = 0; idx <= student_number; idx++) {
		if (idx == student_number) {
			cout << "Can't find the student id: " << temp_id << endl;
			return -1;
		}
		if (temp_id == students[idx].id)
			break;
	}
	// update score
	int temp_score;
	cout << "Score: ";
	cin >> temp_score;
	if (temp_score < 0 || 100 < temp_score) {
		cout << "Failed to edit: invalid exam score!\n";
		return -1;
	}
	if (selection == 1)
		students[idx].midterm_exam_score = temp_score;
	else	// if (selection == 2)
		students[idx].final_exam_score = temp_score;
	//else {
	//	cout << "Enter wrong menu number\n";
	//	return -1;
	//}
	return 1;
}

void print_score_average(student students[], int student_number) {
	int sum = 0;
	double average;
	double std_deviation;

	// evaluate average
	int i;
	for (i = 0; i < student_number; i++)
		sum += students[i].midterm_exam_score + students[i].final_exam_score;
	average = sum / (double)student_number;

	// evaluate standard deviation
	for (i = 0, sum = 0; i < student_number; i++)
		sum += pow(students[i].midterm_exam_score + students[i].final_exam_score - average, 2);
	std_deviation = sqrt(sum / (double)student_number);

	// display
	//cout << fixed;
	cout.precision(5);
	cout << "Average score: " << average << endl;
	cout << "Standard deviation: " << std_deviation << endl;
}

void sort_students(student students[], int student_number) {
	// bubble sort
	student temp;
	for (int length = student_number - 1; 1 < length; length--) {
		for (int i = 0; i < length - 1; i++) {
			if (students[i].midterm_exam_score + students[i].final_exam_score < students[i + 1].midterm_exam_score + students[i + 1].final_exam_score ||
				(students[i].midterm_exam_score + students[i].final_exam_score == students[i + 1].midterm_exam_score + students[i + 1].final_exam_score && students[i].id > students[i + 1].id)) {
				temp = students[i];
				students[i] = students[i + 1];
				students[i + 1] = temp;
			}
		}
	}
}

void print_score_list(student students[], int student_number) {
	sort_students(students, student_number);

	// display score
	for (int i = 0; i < student_number; i++) {
		cout << students[i].id << " " << students[i].name << " ";
		cout << students[i].midterm_exam_score << " " << students[i].final_exam_score << " ";
		cout << students[i].midterm_exam_score + students[i].final_exam_score << endl;
	}
}

void print_grade_list(student students[], int student_number) {
	// rank the students
	sort_students(students, student_number);

	// student number of each grade
	int a_num = student_number * 3 / 10;
	a_num = a_num < 1 ? 1 : a_num;
	int b_num = student_number * 7 / 10;
	b_num = b_num < 2 ? 2 : b_num;
	int c_num = student_number * 9 / 10;
	c_num = c_num < 3 ? 3 : c_num;

	// evaluate Grade
	for (int i = 0; i < student_number; i++) {
		// 상위 30% 이내 : A
		if (i <= a_num && 150 < students[i].midterm_exam_score + students[i].final_exam_score)
			students[i].grade = 'A';
		// 상위 70% 이내 : B
		else if (i <= b_num && 100 < students[i].midterm_exam_score + students[i].final_exam_score)
			students[i].grade = 'B';
		// 하위 10% 이내가 아님 : C
		else if (i <= c_num && 50 < students[i].midterm_exam_score + students[i].final_exam_score)
			students[i].grade = 'C';
		// 나머지는 D
		else
			students[i].grade = 'D';
		// 재수강 시 감점
		if (students[i].retake == 1 && students[i].grade != 'D')
			students[i].grade += 1;
	}

	// display grade
	for (int i = 0; i < student_number; i++) {
		cout << students[i].id << " " << students[i].name << " ";
		cout << students[i].midterm_exam_score + students[i].final_exam_score << " " << students[i].retake << " ";
		cout << students[i].grade << endl;
	}
}