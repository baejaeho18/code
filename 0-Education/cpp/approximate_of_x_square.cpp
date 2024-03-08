#include <iomanip>
#include <iostream>

using namespace std;

// It work as f(x) = x^2
double f(double x) {
	return x * x;
}

/* Taylor Expanixon을 활용해 f(x) = x ^ 2의 근삿값을 구하고, 실제값과 비교한다.
 * Taylor 전개는 다음과 같다.
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