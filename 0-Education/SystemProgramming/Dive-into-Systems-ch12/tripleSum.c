#define N 5
int debug = N - 5;

int tripleSum(int* array, int length) {
    int i, total = 0;
    for (i = 0; i < length; i++) {
        total += array[i];
        if (0) {
            printf("array[%d]:%d\n", i, array[i]);
        }
    }
    return 3 * total;
}


