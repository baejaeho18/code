# 1.	프로그램 개요
성적 관리를 위해, 각 학생의 정보를 입력 받고, 자동으로 전체 평균과 각 학생들의 Grade 성적을 출력하는 프로그램이다. 아래 메뉴 화면에서 기능들을 확인할 수 있다.
 
1번 기능은 학생의 학번과 이름, 중간고사 점수, 기말고사 점수, 재수강 여부를 입력 받는 것이다. 각 정보들의 제약조건과 맞지 않으면 “Failed to add: ~~~” 를 출력하고, 학생 정보 입력 작업을 중단한다. 2번 기능은 이미 입력된 학생의 정보를 수정한다. 학번과 수정할 점수를 입력하면, 일치하는 학번을 찾은 후, 수정한다. 마찬가지로 학생 정보 포맷과 맞지 않거나, 존재하지 않는 학번이라면 수정 작업을 중단한다. 3번 기능은 입력 받은 모든 학생들의 평균과 표준편차를 출력한다. 이때, 유효숫자 5자리까지만 출력한다. 4번 기능은 중간기말점수를 합산한 점수를 기준으로 높은 순서부터 학생 정보를 출력한다. 만약 동점자가 있다면, 학번 낮은 순서로 출력한다. 5번 기능은 학생들의 최종 등급을 산출하여 출력한다. A, B, C, D 등급을 주어진 조건에 따라 산정하고, 출력한다.
prob1_49004728.sln을 열어 score_manager.cpp를 2가지 testcase로 실행한 결과이다. Testcase1(Problem1-3_testcase.txt)은 다음과 같다.
 
입력 후, 기능 3과 4를 테스트한 결과는 다음과 같다.
 
2번기능과 4번기능을 테스트한 결과는 다음과 같다.
Testcase2(Problem1-5_testcase.txt)는 1번기능과 5번기능을 점검한다. Testcase2 내용은 다음과 같다.
 
실행 결과는 다음과 같다.
 

# 2.	프로그램의 구조 및 알고리즘
본 프로그램은 크게 학생 정보를 담는 struct student와 메뉴별 기능을 호출하는 main 함수, 각 메뉴별 기능을 구현한 함수들로 이루어져있다. 

첫째, struct student는 1번 기능에서 입력 받는 학생정보의 포맷을 검증하고 struct에 저장하는 membef function과, 그 학생정보들을 저장하는 member variable롤 이루어져 있다. 입력 받는 Member variable에는 학번(id), 이름(name), 중간고사 점수(midterm_exam_score), 기말고사 점수(final_exam_score), 재수강 여부(retake)로 5가지가 있다. 마지막으로 중간과 기말 점수를 합산하여 상대 평가로 책정되는 학점(grade)이 member variable로 있다. 5개 member function은 입력 받는 5가지 member variable을 각각 받아 포맷에 맞는지 검사한 후, 맞으면 1을 형식에 맞지 않으면 -1을 반환한다. 각 member function을 호출한 함수에서는 -1을 반환 받으면 “Failed to add: ~~~” 를 출력하고 입력 작업을 중지한다. 

둘째, main 함수는 최대 학생수(100명)에 맞게 student 타입의 배열 students를 선언하고, exit(6)을 입력 받을 때까지 메뉴창 출력과 함께 메뉴를 선택하도록 반복한다. 각 기능 선택시, 해당하는 함수를 호출하고, 성공적으로 실행되면 완료메시지를 출력한다. 1번 기능에서는 특히 학생 정보 입력이 완료될 때마다 실제 학생 수인 student_number에 1씩 더한다. 6번 기능(exit)에서는 반복을 중지하기 위해 break문을 포함한다.

각 기능별로 함수들이 존재한다. 1번 기능은 add_student(student * new_student)를 호출한다. 해당 함수에서 초기화된 struct student를 함수 밖에서도 쓰기 위해 포인터 타입으로 매개변수를 작성했다. add_student() 함수는 student의 member function을 차례대로 호출하며 -1이 반환될 경우 Failed 메시지를 출력하고 모두 1을 반환하면 main함수에 학생 정보 추가 성공을 알린다. 2번 기능은 edit_score(student students[], int student_number)를 호출한다. 2번 기능부터는 이미 저장된 학생 정보들을 활용해야하기 떄문에 students[]를 매개변수로 받는다. 마찬가지로 입력 받은 학번(temp_id)가 올바른 형식인지 확인한 후, 존재한다면 점수를 수정한다. 존재하지 않는다면 오류 메시지를 출력한다. 3번 기능은 print_score_average(student students[], int student_number)를 호출한다. 

students에 저장된 모든 점수를 순회하며 더하고 이를 통해 average와 std_deviation을 구해 출력한다. 이때 5자리 유효숫자를 맞추기 위해 cout.precision(5)를 사용하였다. 4번 기능은 print_score_list(student students[], int student_number)를 호출한다. 우선 sort_students() 함수를 활용해 현재까지 저장된 모든 학생 정보를 주어진 조건에 맞게 bubble sort한다. sort_students() 함수의 구현은 다음과 같다.
```c++
void sort_students(student students[], int student_number) {
	// bubble sort
	student temp;
	for (int length = student_number; 1 < length; length--) {
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
```
Sorting이 완료되었다면, 순서대로 학생 정보를 출력한다. 5번 기능 역시 sort_stuents() 함수를 활용해 정렬한 후, Grade를 산출한다. print_grade_list(student students[], int student_number) 함수는 sorting이 되었다는 전제 하에, 그리고 동점자가 없다는 전제 하에 성립한다. 우선 A 학점자 수와 B 학점자 수, C 학점자 수를 student_number에 각각 0.3, 0.7, 0.9를 곱해 얻는다. 정렬된 학생정보에 따라 index가 A 학점자 수 미만이고, A학점 최소 점수보다 중간기말 합산 점수가 높을 때, A를 부여한다. B와 C도 마찬간지다. 이후, 재수강 여부(retake)를 검사하여 참(1)이면 grade에 1을 더하여 학점을 한단계씩 낮춘다. 이는 grade를 member variable로 선언할 때, char 타입으로 선언했기 때문에 가능하다. 모든 grade가 책정되면, 순서대로 학생 정보를 형식에 맞게 출력한다.

# 3.	토론 및 개선
1번 기능을 구현하기 위해 struct 타입의 변수를 어떻게 함수의 매개변수로 넘길 것인지 고민하게 되었다. 강의에서 배운 Call by value와 Call by reference를 참고하며 코드를 작성하였다.

5번 기능에서 어떻게 branch 문을 최소화할지 고민하는 것이 가장 오래 걸렸다. 학점을 산출하려면 각 학생들의 총점을 기준으로 정렬하는 것이 반드시 필요한 절차였다. 이에 더해, 중간기말 합산 점수가 최소 점수를 만족하는지, 재수강을 하였는지 검토하려면 또 한번씩 students[]를 순회해야 했다. 이를 시간 복잡도로 표현하면 N^2 + 2N 일 것이다. 본인은 이 절차 자체를 줄이기는 어렵다고 보고, sorting하는 함수를 분리하였다. 5번 기능을 호출할 때마다 grade를 새로 산출하기 위해 위 작업을 반복하는 것이 아니라, 4번 혹은 5번 기능을 사용할 때마다 조금씩 sorting 시켜 최대한 반복되는 작업을 줄여 프로그램 실행 속도를 최소화하려 하였다.

# 4.	참고 문헌
Bubble sort와 시간복잡도: https://aiday.tistory.com/53
