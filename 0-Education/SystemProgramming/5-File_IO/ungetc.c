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
        if (c == '!') {
            c = '+';
        }
        fputc(c, stdout);
    }

    fclose(fp);

    return 0;
}
