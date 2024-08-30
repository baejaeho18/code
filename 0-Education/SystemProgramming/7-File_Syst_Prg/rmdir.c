#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int ret;

    ret = rmdir("/home/barbary/maps");
    if (ret) {
        perror("rmdir");
        exit(EXIT_FAILURE);
    }

    return 0;
}
