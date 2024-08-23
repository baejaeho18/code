#include <stdio.h>

typedef int (*OperationFunc)(int, int);       // define function pointer type

int add(int a, int b) { return a + b; }

int multiply(int a, int b) { return a * b; }

int main() {
    OperationFunc func_ptr;
    func_ptr = add;
    printf("Result of add operation: %d\n", func_ptr(3, 4));

    func_ptr = multiply;
    printf("Result of multiply operation: %d\n", func_ptr(3, 4));

    return 0;
}
