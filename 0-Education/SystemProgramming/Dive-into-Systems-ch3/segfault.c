/* segfault.c  finds the largest element in the array */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initfunc(int* array, int len) {
    for (int i = 1; i <= len; i++)
        array[i] = i;
    return 0;
}
int func(int* array1, int len, int max) {
    max = array1[0];
    for (int i = 1; i < len; i++)
        if (max < array1[i])
            max = array1[i];
    return 0;
}
int main(int argc, char* argv[]) {
    int* arr = malloc(100 * sizeof(int));
    int max = 6;
    if (initfunc(arr, 100) != 0) {
        printf("init error\n");
        exit(1);
    }
    if (func(arr, 100, max) != 0) {
        printf("func error\n");
        exit(1);
    }
    printf("max value in the array is %d\n", max);
    exit(0);
}