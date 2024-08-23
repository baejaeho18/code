#include <stdio.h>

int main() {
    
#define ADD_COR(x, y) ((x) + (y)) // Correct
#define ADD_INC(x, y) x + y       // Incorrect

    int result;
    result = 2 * ADD_INC(3, 4);     // Expands to: 2 * 3 + 4 -> (10)
    printf("Result of ADD_COR: %d", result);
    result = 2 * ADD_COR(3, 4);    // Expands to: 2 * (3+4) -> (14)
    printf("Result of ADD_INC: %d", result);

    return 0;
}


