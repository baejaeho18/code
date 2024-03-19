#pragma once
//#ifndef BITWISE_DISPLAYER_H
//#define BITWISE_DISPLAYER_H

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

template<typename T>
string bitLayout(T value) {
    unsigned char* bytes = reinterpret_cast<unsigned char*>(&value);
    size_t size = sizeof(T);

    string result;
    for (int i = size - 1; i >= 0; --i) {
        bitset<8> bits(bytes[i]);
        result += bits.to_string() + " ";
    }
    result += "(" + to_string(size) + " bytes)";

    return result;
}

//#endif