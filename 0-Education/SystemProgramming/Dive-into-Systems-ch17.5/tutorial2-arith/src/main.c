#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

int main() {
    int a = 10, b = 5;
    printf("Add: %d\n", add(a, b));
    printf("Sub: %d\n", sub(a, b));
    printf("Mul: %d\n", mul(a, b));
    printf("Div: %d\n", div(a, b));
    return 0;
}
