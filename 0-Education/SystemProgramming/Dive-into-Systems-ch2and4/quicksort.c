#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 스왑 함수
void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

// 제네릭 퀵소트 함수
void my_qsort(void *base, size_t num, size_t size, int (*cmp)(const void *, const void *)) {
    if (num < 2) return;

    char *base_char = (char *)base;
    void *pivot = base_char + (num - 1) * size;
    size_t i = 0;

    for (size_t j = 0; j < num - 1; j++) {
        if (cmp(base_char + j * size, pivot) <= 0) {
            swap(base_char + i * size, base_char + j * size, size);
            i++;
        }
    }
    swap(base_char + i * size, pivot, size);

    my_qsort(base, i, size, cmp);
    my_qsort(base_char + (i + 1) * size, num - i - 1, size, cmp);
}

// 제네릭 배열 출력 함수
void print_array(void *array, size_t size, size_t elem_size, void (*print_elem)(const void *)) {
    for (size_t i = 0; i < size; i++) {
        print_elem((char *)array + i * elem_size);
    }
    printf("\n");
}

// int 타입 비교 함수
int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// char 타입 비교 함수
int compare_char(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// int 타입 출력 함수
void print_int(const void *elem) {
    printf("%d ", *(int *)elem);
}

// char 타입 출력 함수
void print_char(const void *elem) {
    printf("%c ", *(char *)elem);
}

// 메인 함수
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <type> <data...>\n", argv[0]);
        return 1;
    }

    char *type = argv[1];
    size_t num, size;
    int (*cmp)(const void *, const void *);
    void (*print_elem)(const void *);
    void *array;

    if (strcmp(type, "int") == 0) {
        int *int_array = malloc((argc - 2) * sizeof(int));
        if (int_array == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        num = argc - 2;
        for (size_t i = 0; i < num; i++) {
            int_array[i] = atoi(argv[i + 2]);
        }
        size = num;
        array = int_array;
        cmp = compare_int;
        print_elem = print_int;

        printf("Before sorting int array: ");
        print_array(array, size, sizeof(int), print_elem);

        my_qsort(array, size, sizeof(int), cmp);

        printf("After sorting int array: ");
        print_array(array, size, sizeof(int), print_elem);

        free(int_array);
    } else if (strcmp(type, "char") == 0) {
        char *char_array = malloc((argc - 2) * sizeof(char));
        if (char_array == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        num = argc - 2;
        for (size_t i = 0; i < num; i++) {
            char_array[i] = argv[i + 2][0];
        }
        size = num;
        array = char_array;
        cmp = compare_char;
        print_elem = print_char;

        printf("Before sorting char array: ");
        print_array(array, size, sizeof(char), print_elem);

        my_qsort(array, size, sizeof(char), cmp);

        printf("After sorting char array: ");
        print_array(array, size, sizeof(char), print_elem);

        free(char_array);
    } else {
        fprintf(stderr, "Unsupported type: %s. Use 'int' or 'char'.\n", type);
        return 1;
    }

    return 0;
}
