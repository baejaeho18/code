#include <stdio.h>

void appendFiles(char source[], char destination[]) {
    FILE *fp1, *fp2;

    fp1 = fopen(source, "r");
    fp2 = fopen(destination, "a");

    if (!fp1 || !fp2) {
        printf("Unable to open/detect file(s)\n");
        if (fp1) fclose(fp1);
        if (fp2) fclose(fp2);
        return;
    }

    char buf[100];

    while (fgets(buf, sizeof(buf), fp1) != NULL) {
        fprintf(fp2, "%s", buf);
    }

    rewind(fp2);
    while (fgets(buf, sizeof(buf), fp2) != NULL) {
        printf("%s", buf);
    }

    fclose(fp1);
    fclose(fp2);
}

int main() {
    char source[] = "file1.txt";
    char destination[] = "file2.txt";

    appendFiles(source, destination);
    return 0;
}
