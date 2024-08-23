#include <stdio.h>

typedef struct {
    int x, y;
} SAMPLE;

int main() {
    SAMPLE sam1, * ptr;
    ptr = &sam1;

    *ptr.x = 100;   // incorrect: 
    // selection operator (.) proceeds dereference operator (*)
    (*ptr).x = 100; // correct
    ptr->x = 100;   // correct (indirect selection operator)
    sam1.x = 100;
    return 0;
}
