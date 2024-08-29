#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int fd;

    fd = open("home/user1/pearl", O_WRONLY | O_TRUNC);
    if (fd == -1) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    // Do yout operations here

    close(fd);

    return 0;
}
