#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPerfectNum(int n) {
    int sum = 0;
    for (int i=1; i<n; i++) {
        if (n % i == 0)
            sum += i;
    }
    return (sum == n);
}

void findPerfectNum(int n) {
    printf("Perfect number(1-%d): ", n);
    for (int i=1; i<n; i++) 
        if(isPerfectNum(i))
            printf("%d ", i);
}

int main() {

    int range = 100;
    findPerfectNum(range);
    findPerfectNumWithFormula(range);
    return 0;
}