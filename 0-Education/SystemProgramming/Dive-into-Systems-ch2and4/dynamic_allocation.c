#include <stdio.h>

int main(int argc, char * argv[]) {

    int *p_array;
    double *d_array;

    p_array = malloc(sizeof(int) * 50);
    d_array = malloc(sizeof(double) * 100);

    if ( (p_array == NULL) || (d_array == NULL) ) {
        printf("ERROR: malloc failed!\n");
        exit(1);
    }

    for (int i=0; i<50; i++) {
        p_array[i] = 0;
        d_array[i] = 0.0;
    }

    free(p_array);
    p_array = NULL;

    free(d_array);
    d_array = NULL;

    return 0;
}