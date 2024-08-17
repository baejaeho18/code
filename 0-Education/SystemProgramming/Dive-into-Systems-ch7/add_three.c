#include <stdio.h>

int add_three(int x, int y, int z) {
    int result;
    __asm__(
        "movl %1, %%eax\n\t"     		// eax = x
        "addl %2, %%eax\n\t"      		// eax = eax + y
        "addl %3, %%eax"     		// eax = eax + z
        : "=a" (result)        			// Output Operand
        : "r" (x), "r" (y), "r" (z)  		// Input Operands
    );
    return result;
}

int main() {
    int a = 5, b = 10, c = 3;
    int result = add_three(a, b, c);
    printf("Result: %d\n", result);  // Result: 18
    return 0;
}
