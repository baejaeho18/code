#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void print_array(void *array, size_t size, size_t elem_size, void (*print_elem)(const void *)) {
    for (size_t i = 0; i < size; i++) print_elem((char *)array + i * elem_size);
    printf("\n");
}

int compare_int(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int compare_char(const void *a, const void *b) { return (*(char *)a - *(char *)b); }
void print_int(const void *elem) { printf("%d ", *(int *)elem); }
void print_char(const void *elem) { printf("%c", *(char *)elem); }

int main(int argc, char *argv[]) {
     if (argc < 3) {
        fprintf(stderr, "Usage: %s <type> <data...>\n", argv[0]);
        return 1;
    }

    char *type = argv[1];
    size_t size = argc - 2;
    void *array;
    int (*cmp)(const void *, const void *);
    void (*print_elem)(const void *);
    size_t elem_size;

    if (strcmp(type, "int") == 0) {
        elem_size = sizeof(int);
        int *int_array = malloc(size * elem_size);
        if (int_array == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        for (size_t i = 0; i < size; i++) {
            int_array[i] = atoi(argv[i + 2]);
        }
        array = int_array;
        cmp = compare_int;
        print_elem = print_int;
    } else if (strcmp(type, "char") == 0) {
        elem_size = sizeof(char);
        char *char_array = malloc(size * elem_size);
        if (char_array == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        for (size_t i = 0; i < size; i++) {
            char_array[i] = argv[i + 2][0];
        }
        array = char_array;
        cmp = compare_char;
        print_elem = print_char;
    } else {
        fprintf(stderr, "Unsupported type: %s. Use 'int' or 'char'.\n", type);
        return 1;
    }

    printf("Before sorting array: ");
    print_array(array, size, elem_size, print_elem);
    my_qsort(array, size, elem_size, cmp);
    printf("After sorting array: ");
    print_array(array, size, elem_size, print_elem);

    free(array);
    return 0;
}