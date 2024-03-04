#pragma once
#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <iostream>
#include <string>

class complex_number
{
public:
    float real, imag;

    complex_number add(complex_number rhs);
    complex_number subtract(complex_number rhs);
    complex_number multiply(complex_number rhs);
    complex_number divide(complex_number rhs);

    friend std::ostream& operator<<(std::ostream& os, const complex_number& cn);
};

#endif // COMPLEX_NUMBER_H
