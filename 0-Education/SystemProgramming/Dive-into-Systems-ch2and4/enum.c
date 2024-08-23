#include <stdio.h>

enum Color {
    RED,          // 0 by default
    GREEN,        // 1
    BLUE          // 2
};

enum ResponseCode {
    OK = 200,         // Explicitly set to 200
    CREATED = 201,    // 201
    ACCEPTED = 202,   // 202
    NO_CONTENT = 204, // 204
    BAD_REQUEST = 400,// Explicitly set to 400
    UNAUTHORIZED,     // 401 (incrementing by 1 from previous value)
    FORBIDDEN         // 402
};


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
