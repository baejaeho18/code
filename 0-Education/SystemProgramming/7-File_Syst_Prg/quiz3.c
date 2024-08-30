#include <stdio.h>
#include <stdlib.h>

struct person {
    int id;
    char fname[20];
    char lname[20];
};

int main() {
    FILE* infile;
    struct person read_struct;

    if ((infile = fopen("person1.dat", "rb")) == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    fread(&read_struct, sizeof(struct person), 1, infile);

    printf("Name: %s %s\nID: %d\n", read_struct.fname, read_struct.lname, read_struct.id);

    fclose(infile);

    return 0;
}
