#include <stdio.h>

int main() {
    FILE *fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    printf("File number is %d\n", fileno(fp));
    fclose(fp);
    return 0;
}
