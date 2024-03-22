#pragma once

#include <iostream>
#include <cmath>

using namespace std;

struct student {
	int id;					// 8자리 양의 정수
	string name;			// 알파벳 10개 이하의 공백 미포함 문자열
	int midterm_exam_score;	// 0~100
	int final_exam_score;	// 0~100
	int retake;				// 0/1

	int total_score = 0;	// midterm_score + final_score
	char grade ;			// Grade: A, B, C, D

	int set_id() {
		int temp_id;
		cout << "Student id: ";
		cin >> temp_id;
		if (10000000 <= temp_id && temp_id < 100000000) {
			id = temp_id;
			return 1;
		}
		return -1;
	}

	int set_name() {
		string temp_name;
		cout << "Name: ";
		cin >> temp_name;

		// isalphabetic
		for (int i = 0; i < temp_name.size(); i++) {
			if (('a' <= temp_name[i] && temp_name[i] <= 'z') ||
				('A' <= temp_name[i] && temp_name[i] <= 'Z'))
				continue;
			else
				return -1;
		}
		
		// size < 10
		if (0 < temp_name.size() && temp_name.size() <= 10) {
			name = temp_name;
			return 1;
		}
		return -1;
	}

	int set_midterm_exam_scroe() {
		int temp_score;
		cout << "Midterm exam score: ";
		cin >> temp_score;
		if (0 <= temp_score && temp_score <= 100) {
			midterm_exam_score = temp_score;
			total_score += midterm_exam_score;
			return 1;
		}
		return -1;
	}

	int set_final_exam_score() {
		int temp_score;
		cout << "Final exam score : ";
		cin >> temp_score;
		if (0 <= temp_score && temp_score <= 100) {
			midterm_exam_score = temp_score;
			total_score += midterm_exam_score;
			return 1;
		}
		return -1;
	}

	int set_retake() {
		int temp_retake;
		cout << "Retake: ";
		cin >> temp_retake;
		if (temp_retake == 0 || temp_retake == 1) {
			retake = temp_retake;
			return 1;
		}
		return -1;
	}
};

void show_menu();
int add_student(student new_student);
int edit_score(student students[], int student_number);
void print_score_average(student students[], int student_number);
void print_score_list(student students[], int student_number);
void print_grade_list(student students[], int student_number);

void sort_students(student students[], int student_number);