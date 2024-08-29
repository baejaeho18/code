#include <stdio.h>

int main() {
    FILE *fp;
    int c;
    
    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("Error in opening file");
        return -1;
    }

    while ((c = fgetc(fp)) != EOF) {
        putchar(c); 
    }

    fclose(fp);

    return 0;
}
