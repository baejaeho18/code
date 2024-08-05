#include <stdio.h>
#include <stdlib.h>

#define MK_ID(n) id##n
#define GENERIC_SWAP(ELEM_TYPE) void swap_##ELEM_TYPE(ELEM_TYPE *a, ELEM_TYPE *b) \
                                    { \
                                        ELEM_TYPE t; \
                                        t = *a; \
                                        *a = *b; \
                                        *b = t; \
                                    }
#define PRINT_INT(x) printf(#x " = %d\n", x)

int main()
{
#ifdef __LINUX
    printf(">> This code is for Linux system.\n");
#else
    printf(">> This code is for Windows system.\n");
#endif

    float *MK_ID(0) = (float *)malloc(sizeof(float));
    float *MK_ID(1) = (float *)malloc(sizeof(float));
    int *MK_ID(2) = (int *)malloc(sizeof(int));
    int *MK_ID(3) = (int *)malloc(sizeof(int));

    if (MK_ID(0) == NULL || MK_ID(1) == NULL || MK_ID(2) == NULL || MK_ID(3) == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    GENERIC_SWAP(int);
    GENERIC_SWAP(float);

    *MK_ID(0) = 0.0; 
    *MK_ID(1) = 1.1;
    *MK_ID(2) = 2;   
    *MK_ID(3) = 3;

    swap_float(id0, id1);
    swap_int(id2, id3);

#if DEBUG
    printf("id0: %.2f, id1: %.2f\n", *MK_ID(0), *MK_ID(1));
    PRINT_INT(*id2);
    PRINT_INT(*id3);
#else
    PRINT_INT(*id2);
    PRINT_INT(*id3);
#endif

    free(MK_ID(0));
    free(MK_ID(1));
    free(MK_ID(2));
    free(MK_ID(3));

    return 0;
}
