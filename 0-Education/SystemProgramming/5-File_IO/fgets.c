#include <stdio.h>

int main() {
    FILE *fp;
    char str[60];

    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    if (fgets(str, sizeof(str), fp) != NULL) {
        puts(str);
    } else {
        perror("Error reading file");
    }

    fclose(fp);

    return 0;
}
