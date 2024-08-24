#include <stdio.h>

int main() {
    int (*func)();
    func = printf;
    (*func)("함수 포인터를 설명합니다.\n");
    return 0;
}
