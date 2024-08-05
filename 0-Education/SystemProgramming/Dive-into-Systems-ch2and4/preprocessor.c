#include <stdio.h>

#define MK_ID(n) id##n
#define GENERIC_SWAP(NAME, ELEM_TYPE) void NAME(ELEM_TYPE *a, ELEM_TYPE *b) \
                                    { \
                                        ELEM_TYPE t; \
                                        t = *a; \
                                        *a = *b; \
                                        *b = t; \
                                    }
#define PRINT_INT(x) printf(#x " = %d\n", x)

int main()
{
#pragma message("main")

#ifdef __LINUX
    printf(">> This code is for Linux system.\n");
#else
    printf(">> This code is for Windows system.\n");
#endif

    float *MK_ID(0), *MK_ID(1);
    int *MK_ID(2), *MK_ID(3);
    GENERIC_SWAP(swap_int, int);
    GENERIC_SWAP(swap_float, float);

    *id0 = 0.0; *id1 = 1.1;
    *id2 = 2;   *id3 = 3;

    swap_float(id0, id1);
    swap_int(id2, id3);

#if DEBUG
    printf("id0: %f, id1: %f\n", *id0, *id1);
    PRINT_INT(id2);
    PRINT_INT(id3);
#else
    PRINT_INT(id2);
    PRINT_INT(id3);
#endif


    return 0;
}