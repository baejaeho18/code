#include <stdio.h>
#include <stdlib.h>

struct person {
    int id;
    char fname[20];
    char lname[20];
};

int main() {
    FILE* outfile;

    outfile = fopen("person.bin", "wb");
    if (outfile == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    struct person input1 = { 1, "rohan", "sharma" };

    int flag = fwrite(&input1, sizeof(struct person), 1, outfile);
    if (flag) {
        printf("Contents of the structure written successfully\n");
    } else {
        printf("Error writing to file\n");
    }

    fclose(outfile);

    return 0;
}
