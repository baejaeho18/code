#include <stdio.h>

int main() {
    int len;
    FILE *fp = fopen("file.txt", "w+");
    if (fp == NULL) perror("Error open");
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fclose(fp);
    printf("Size of file: %d bytes", len);
    return 0;
}
