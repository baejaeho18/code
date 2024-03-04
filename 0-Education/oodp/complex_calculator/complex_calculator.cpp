#include <iostream>
#include <string>
//#include "complex_number_oop.h"
#include "complex_number_generic.h"

using namespace std;

int main()
{
    string op;
    complex_number<float> a, b, c;
    complex_number<double> ad, bd, cd;

    cout << "Complex number calculator" << endl;
    while (1) {
        cout << "What operation do you want to compute?(EXIT) ";
        cin >> op;
        if (op == "+" || op == "-" || op == "*" || op == "/") {
            cout << "Input the first number (real, imaginary): ";
            cin >> a.real >> a.imag;
            cout << "Input the second number (real, imaginary): ";
            cin >> b.real >> b.imag;

            if (op == "+") {
                c = a.add(b);
                cout << a << " + " << b << " = " << c << endl;
            }
            else if (op == "-") {
                c = a.subtract(b);
                cout << a << " - " << b << " = " << c << endl;
            }
            else if (op == "*") {
                c = a.multiply(b);
                cout << a << " * " << b << " = " << c << endl;
            }
            else if (op == "/") {
                c = a.divide(b);
                cout << a << " / " << b << " = " << c << endl;
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
