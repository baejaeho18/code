#include <iomanip>
#include <iostream>

using namespace std;

// It work as f(x) = x^2
double f(double x) {
	return x * x;
}

/* Taylor Expanixon�� Ȱ���� f(x) = x ^ 2�� �ٻ��� ���ϰ�, �������� ���Ѵ�.
 * Taylor ������ ������ ����.
 * f(x) ~ f(x_0) + f'(x_0)(x-x_0)
 * f'(x_0) ~ ( f(x_0 + h) - f(x_0) ) / h
 * where, f(x) = x^2
*/
int main() {

	double x_0, x, h;
	double exact_num;
	double approx_num;

	// Input
	cin >> x_0 >> x >> h;

	// Operation
	// 1. Exact Answer : f(x) means x square
	exact_num = f(x);
	// 2. Approximate Answer = f(x_0) + f'(x_0)(x-x_0) = f(x_0) + (x - x_0)(f(x_0 + h) - f(x_0))/h
	approx_num = f(x_0) + (x - x_0) * (f(x_0 + h) - f(x_0)) / h;

	// Output : just followed the notification
	cout << setprecision(5) << "Exact answer is " << exact_num << "\n" << "Approximate answer is " << approx_num << endl;

	return 0;
}