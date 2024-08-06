#include <stdio.h>

int add(int a, int b) {
    int result;
    // 인라인 어셈블리 코드
    __asm__ (
        "addl %%ebx, %%eax;"  // eax = eax + ebx
        : "=a" (result)       // 출력: result 변수에 eax 레지스터 값을 저장
        : "a" (a), "b" (b)    // 입력: a는 eax 레지스터에, b는 ebx 레지스터에 저장
    );
    return result;
}

int main() {
    int a = 5;
    int b = 3;
    int result = add(a, b);
    printf("Result: %d\n", result); // 결과 출력
    return 0;
}
