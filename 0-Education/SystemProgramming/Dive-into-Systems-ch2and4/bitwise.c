#include <stdio.h>

int main() {
    unsigned char a = 13;
    unsigned char b = 22;

    unsigned char sl_a = a << 3;  // Shift left by 3 bits
    unsigned char sr_a = a >> 3;  // Shift right by 3 bits
    unsigned char neg_a = ~a;     // Bitwise NOT
    unsigned char a_and_b = a & b;  // Bitwise AND
    unsigned char a_or_b = a | b;   // Bitwise OR
    unsigned char a_xor_b = a ^ b;  // Bitwise XOR

    printf("a = %d \t: 0x%02X\n", a, a);
    printf("b = %d \t: 0x%02X\n", b, b);
    printf("sl_a = %d \t: 0x%02X\n", sl_a, sl_a);
    printf("sr_a = %d \t: 0x%02X\n", sr_a, sr_a);
    printf("neg_a = %d \t: 0x%02X\n", neg_a, neg_a);
    printf("a_and_b = %d \t: 0x%02X\n", a_and_b, a_and_b);
    printf("a_or_b = %d \t: 0x%02X\n", a_or_b, a_or_b);
    printf("a_xor_b = %d \t: 0x%02X\n", a_xor_b, a_xor_b);

    return 0;
}


