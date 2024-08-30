#include <stdio.h>

int main() {
    char buf[BUFSIZ];
    setvbuf(stdout, buf, _IOFBF, BUFSIZ);
    printf("Arrr!\n");
    return 0;
}
