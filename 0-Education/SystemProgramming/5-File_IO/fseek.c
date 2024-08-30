#include <stdio.h>

int main() {
    FILE *fp = fopen("file.txt", "w+");
    fputs("This is tutorials-point.com", fp);
    fseek(fp, 7, SEEK_SET);
    fputs(" C Programming Language", fp);
    fclose(fp);
    return 0;
}
