#include <stdio.h>

int add_three(int x, int y, int z) {
    int result;
    __asm__(
        "movl %2, %%eax;"     		// eax = a
        "addl %3, %%eax;"      		// eax = eax + b
        "addl %4, %%eax;"     		// eax = eax + c
        : "=a" (result)        		// Output Operand
        : "0" (x), "r" (y), "r" (z)  		// Input Operands
    );
    return result;
}

int main() {
    int a = 5, b = 10, c = 3;
    int result = add_three(a, b, c);
    printf("Result: %d\n", result);  // Result: 18
    return 0;
}
