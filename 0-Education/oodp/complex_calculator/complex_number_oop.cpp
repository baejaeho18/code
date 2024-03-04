#include "complex_number.h"

complex_number complex_number::add(complex_number rhs) {
    complex_number ret;
    ret.real = real + rhs.real;
    ret.imag = imag + rhs.imag;
    return ret;
}

complex_number complex_number::subtract(complex_number rhs) {
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

std::ostream& operator<<(std::ostream& os, const complex_number& cn) {
    os << cn.real << (cn.imag >= 0 ? "+" : "") << cn.imag << "i";
    return os;
}
