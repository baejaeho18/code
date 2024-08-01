#include <stdio.h>

int main(int argc, char * argv[]) {
    int i, j, c;
    // 1-layer Array Memory Layout
    int iarray[6];
    char carray[4];
    printf("Address\tElement\n-------\t---------\n");
    for (i=0; i<6; i++)
        printf("%d: iarray[%d] %d\n", (void *)(iarray+i), i, *(iarray+i));
    printf("Address\tElement\n-------\t---------\n");
    for (c=0; c<4; c++)
        printf("%d: carray[%d] %d\n", (void *)(carray+c), c, carray[c]);

    // static_allocated 2-layer Array Memory Layout
    short little[2][3] = {1, 2, 3, 4, 5, 6};
    printf("Address\tElement\n-------\t---------\n");
    for (i=0; i<2; i++)
        for (j=0; j<3; j++)
            printf("%d: little[%d][%d] %d\n", (&little[i][j]), i, j, little[i][j]); // access by row_index and col_index




    return 0;
}