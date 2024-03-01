#include <iostream>
#include <string>

using namespace std;

class complex_number
{
public:
	float real, imag;

	//operation | rhs: right-hand-size
	complex_number add(complex_number rhs);
	complex_number substract(complex_number rhs);
	complex_number multiply(complex_number rhs);
	complex_number divide(complex_number rhs);
};

complex_number complex_number::add(complex_number rhs) {
	complex_number ret;		// ret: return
	ret.real = real + rhs.real;
	ret.imag = imag + rhs.imag;
	return ret;
}

complex_number complex_number::substract(complex_number rhs) {
	complex_number ret;
	ret.real = real - rhs.real;
	ret.imag = imag - rhs.imag;
	return ret;
}

complex_number complex_number::multiply(complex_number rhs) {
	complex_number ret;
	ret.real = (real * rhs.real) - (imag * rhs.imag);
	ret.imag = (real * rhs.imag) + (imag * rhs.real);
	return ret;
}

complex_number complex_number::divide(complex_number rhs) {
	complex_number ret;
	float denominator = (rhs.real * rhs.real) + (rhs.imag * rhs.imag);
	ret.real = ((real * rhs.real) + (imag * rhs.imag)) / denominator;
	ret.imag = ((imag * rhs.real) - (real * rhs.imag)) / denominator;
	return ret;
}

int main()
{
	string op;
	complex_number a, b, c;

	cout << "Complex number calculator" << endl;
	while (1) {
		cout << "What operation do you want to compute? ";
		cin >> op;
		if (op == "+" || op == "-" || op == "*" || op == "/") {
			cout << "Input the first number (real, imaginary): ";
			cin >> a.real >> a.imag;
			cout << "Input the second number (Real, imaginzry): ";
			cin >> b.real >> b.imag;

			if (op == "+") {
				c = a.add(b);
				cout << "(" << a.real << "+" << a.imag << "i" << ")"
					<< " + " 
					<< "(" << b.real << "+" << b.imag << "i" << ")"
					<< " = " 
					<< "(" << c.real << "+" << c.imag << "i" << ")" << endl;
			}
			else if (op == "-") {
				c = a.substract(b);
				cout << "(" << a.real << "+" << a.imag << "i" << ")"
					<< " - " 
					<< "(" << b.real << "+" << b.imag << "i" << ")"
					<< " = " 
					<< "(" << c.real << "+" << c.imag << "i" << ")" << endl;
			}
			else if (op == "*") {
				c = a.multiply(b);
				cout << "(" << a.real << "+" << a.imag << "i" << ")"
					<< " * " 
					<< "(" << b.real << "+" << b.imag << "i" << ")"
					<< " = " 
					<< "(" << c.real << "+" << c.imag << "i" << ")" << endl;
			}
			else if (op == "/") {
				c = a.divide(b);
				cout << "(" << a.real << "+" << a.imag << "i" << ")"
					<< " / "
					<< "(" << b.real << "+" << b.imag << "i" << ")"
					<< " = " 
					<< "(" << c.real << "+" << c.imag << "i" << ")" << endl;
			}
		}
		else if (op == "EXIT") {
			break;
		}
		else {
			printf("Not supported operation!\n");
		}
	}
}