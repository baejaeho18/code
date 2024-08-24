#include <stdio.h>
#include <stdlib.h>

enum Cal { ADD, SUB, DIV, MUL };

// 함수 선언
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int div(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero.\n");
        exit(EXIT_FAILURE);
    }
    return a / b;
}
int mul(int a, int b) { return a * b; }

// 함수 포인터 배열
int (*cal[])(int, int) = { add, sub, div, mul };

// 사용자 입력을 받기 위한 함수들
enum Cal getcmd() {
    int cmd;
    printf("Enter command (0: ADD, 1: SUB, 2: DIV, 3: MUL): ");
    if (scanf("%d", &cmd) != 1 || cmd < 0 || cmd > 3) {
        printf("Invalid command.\n");
        return -1;
    }
    return (enum Cal)cmd;
}

int getarg() {
    int arg;
    printf("Enter argument: ");
    if (scanf("%d", &arg) != 1) {
        printf("Invalid input.\n");
        exit(EXIT_FAILURE);
    }
    return arg;
}

int main() {
    int res = 0, arg1, arg2;
    enum Cal cmd;

    for (;;) {
        printf("> ");
        if ((cmd = getcmd()) == -1) break;
        arg1 = getarg();
        arg2 = getarg();
        res = (*cal[cmd])(arg1, arg2);
        printf("Result: %d\n", res);
    }

    return 0;
}
