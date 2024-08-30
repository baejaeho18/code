#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *fptr1, *fptr2;
    int c;

    if (argc < 3) {
        printf("Usage: %s <src> <dest>\n", argv[0]);
        exit(1);
    }

    fptr1 = fopen(argv[1], "r");
    if (fptr1 == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        exit(1);
    }

    fptr2 = fopen(argv[2], "w");
    if (fptr2 == NULL) {
        printf("Cannot open file %s\n", argv[2]);
        fclose(fptr1);
        exit(1);
    }

    while ((c = fgetc(fptr1)) != EOF) {
        fputc(c, fptr2);
    }

    printf("Contents copied to %s\n", argv[2]);

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}
