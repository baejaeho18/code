#include <stdio.h>
#include <string.h>

int main() {
    float averages[30];
    char name[20];
    int i;

    for (i=0; i<10; i++) {
        averages[i] = 0.0 + i;
        name[i] = 'a' + i;
    }
    name[10] = '\0';

    printf("%g %c %s\n", averages[3], name[3], name);

    strcpy(name, "Hello");
    printf("%s\n", name);

    return 0;
}