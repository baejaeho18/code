#include <iostream>

using namespace std;

int modulo10(int x) {
	// return x - (x / 10) * 10;
	// I thought I can not use % Operator, but it's not true
	return x % 10;
}

/*
* ���� ���� ��
* 1. �� ���� �̴ϼ� �̸��� �����Ͽ� ���´�
* 2. �� ���ڸ� �ƽ�Ű �ڵ�� ��ȯ�Ͽ� �� ���� �ڸ��� �����´�
* 3. �̿��� ���鳢�� ���� �� ���� �ڸ��� �����´�
* ����) DH MG
* D M H G
* 8 7 2 1
* 5 9 3
* 4 2
* The chemistry between DH and MG is 42%
*
* Constraints:
* 1. �̸��� ��� ���� �빮��
* 2. 00�� ��� 100%�� ǥ��
* 3. 2�� �ƴ� ��ȿ���ڰ� �ƴ� 0�� �����Ͽ� ���(02 -> 2%)
*/
int main() {


	// Input
	char name1[3];	// last index is for end symbol(\0)
	char name2[3];
	cin >> name1 >> name2;

	// Operation
	// 1. change char to ASCII code
	int nums[5] = { name1[0], name2[0], name1[1], name2[1] };
	// 2. Modulus Operation
	int four_digits[5] = { modulo10(nums[0]), modulo10(nums[1]), modulo10(nums[2]), modulo10(nums[3]) };
	int three_digits[4] = { modulo10(four_digits[0] + four_digits[1]), modulo10(four_digits[1] + four_digits[2]), modulo10(four_digits[2] + four_digits[3]) };
	int two_digits[3] = { modulo10(three_digits[0] + three_digits[1]), modulo10(three_digits[1] + three_digits[2]) };
	int percentage = two_digits[0] * 10 + two_digits[1];

	// I have to change this statement to use only basic math operator
	percentage = percentage == 0 ? 100 : percentage;
	// how could be?


	// Output
	cout << name1[0] << " " << name2[0] << " " << name1[1] << " " << name2[1] << endl;
	cout << four_digits[0] << " " << four_digits[1] << " " << four_digits[2] << " " << four_digits[3] << endl;
	cout << three_digits[0] << " " << three_digits[1] << " " << three_digits[2] << endl;
	cout << two_digits[0] << " " << two_digits[1] << endl;
	cout << "The chemistry between " << name1 << " and " << name2 << " is " << percentage << "%." << endl;

	return 0;
}