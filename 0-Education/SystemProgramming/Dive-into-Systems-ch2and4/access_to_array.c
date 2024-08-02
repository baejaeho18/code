#include <stdio.h>
#include <stdlib.h> // for malloc() and free()

#define COLS 3
#define ROWS 2

int main(int argc, char * argv[]) {
    int i, j, c;
    // 1) 1-Layer Array Memory Layout
    int iarray[6];
    char carray[4];

    printf("Address\tElement\n-------\t---------\n");
    for (i=0; i<6; i++)
        printf("%d: iarray[%d] %d\n", iarray+i, i, *(iarray+i));
    printf("Address\tElement\n-------\t---------\n");
    for (c=0; c<4; c++)
        printf("%d: carray[%d] %d\n", carray+c, c, carray[c]);
        // printf("%p: carray[%d] %d\n", (void *)(carray+c), c, carray[c]); // original address with Hexa decimal
        // printf("%llu: carray[%d] %d\n", (unsigned long long)(uintptr_t)(carray+c), c, carray[c]);    // correct formatting

    // 2) Static Allocated 2-Layer Array Memory Layout
    short little[2][3] = {1, 2, 3, 4, 5, 6};

    printf("Address\tElement\n-------\t---------\n");
    for (i=0; i<2; i++)
        for (j=0; j<3; j++)
            printf("%d: little[%d][%d] %hd\n", (void *)(&little[i][j]), i, j, little[i][j]); // access by row_index and col_index

    // 3) Dynamic Allocated 2-Layer Array Memory Layout #1 : Call malloc once
    int *two_d_array = malloc(sizeof(int) * COLS * ROWS);

    printf("Address\tElement\n-------\t---------\n");
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            two_d_array[i*COLS+j] = i * COLS + j;    // can not use [i][j]
            printf("%d: two_d_array[%d][%d] %d\n", two_d_array+i*COLS+j, i, j, *(two_d_array+i*COLS+j));
        }
    }
    free(two_d_array);
    two_d_array = NULL;

    // 4) Dynamic Allocated 2-Layer Array Memory Layout #2 : Call malloc (1 + number of COLS) times
    int **two_d_friendly_array = malloc(sizeof(int*) * ROWS);
    printf("Address\tElement\n-------\t---------\n");
    for (i=0; i<ROWS; i++) {
        two_d_friendly_array[i] = malloc(sizeof(int) * COLS);
        printf("%d: two_d_friendly_array[%d] %d\n", &two_d_friendly_array[i], i, two_d_friendly_array[i]);  // 64-bit or 32-bit
    }
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            two_d_friendly_array[i][j] = i * COLS + j;    // Now, programmer can use [i][j]
            printf("%d: two_d_friendly_array[%d][%d] %d\n", &two_d_friendly_array[i][j], i, j, two_d_friendly_array[i][j]); 
        }
    }
    for (i = 0; i < ROWS; i++)
        free(two_d_friendly_array[i]);
    free(two_d_friendly_array);
    two_d_friendly_array = NULL;

    return 0;
}