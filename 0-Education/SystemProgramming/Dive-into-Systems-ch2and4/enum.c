#include <stdio.h>

#define MAX_SIZE 10
enum Status { SUCCESS, FAILURE };

enum Status checkSize(int size) {
    return (size <= MAX_SIZE) ? SUCCESS : FAILURE;
}

int main() {
    int size = 8;
    if (checkSize(size) == SUCCESS) 
        printf("Size is within limits.\n");
    else 
        printf("Size exceeds limits.\n");
    return 0;
}
