#include <stdio.h>

int main(int argc, char * argv[]) {

    // 1-layer Array Memory Layout
    int iarray[6];
    char carray[4];
    printf("Address\tElement\n-------\t---------\n");
    for (int i=0; i<6; i++)
        printf("%d: iarray[%d] %d\n", iarray+i, i, *(iarray+i));
    for (int c=0; c<4; c++)
        printf("%d: carray[%d] %d\n", carray+c, c, carray[c]);



    return 0;
}