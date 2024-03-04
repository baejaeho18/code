#pragma once

#include <iostream>

template<typename component_type>
class complex_number
{
public:
    component_type real, imag;

    complex_number<component_type> add(const complex_number<component_type>& rhs) const;
    complex_number<component_type> subtract(const complex_number<component_type>& rhs) const;
    complex_number<component_type> multiply(const complex_number<component_type>& rhs) const;
    complex_number<component_type> divide(const complex_number<component_type>& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const complex_number<component_type>& cn) {
        os << cn.real << (cn.imag >= 0 ? "+" : "") << cn.imag << "i";
        return os;
    };
};

template<typename component_type>
complex_number<component_type> complex_number<component_type>::add(const complex_number<component_type>& rhs) const {
    complex_number<component_type> ret;
    ret.real = real + rhs.real;
    ret.imag = imag + rhs.imag;
    return ret;
}

template<typename component_type>
complex_number<component_type> complex_number<component_type>::subtract(const complex_number<component_type>& rhs) const {
    complex_number<component_type> ret;
    ret.real = real - rhs.real;
    ret.imag = imag - rhs.imag;
    return ret;
}

template<typename component_type>
complex_number<component_type> complex_number<component_type>::multiply(const complex_number<component_type>& rhs) const {
    complex_number<component_type> ret;
    ret.real = (real * rhs.real) - (imag * rhs.imag);
    ret.imag = (real * rhs.imag) + (imag * rhs.real);
    return ret;
}

template<typename component_type>
complex_number<component_type> complex_number<component_type>::divide(const complex_number<component_type>& rhs) const {
    complex_number<component_type> ret;
    component_type denominator = (rhs.real * rhs.real) + (rhs.imag * rhs.imag);
    ret.real = ((real * rhs.real) + (imag * rhs.imag)) / denominator;
    ret.imag = ((imag * rhs.real) - (real * rhs.imag)) / denominator;
    return ret;
}
