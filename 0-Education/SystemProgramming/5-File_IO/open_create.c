#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>

int main() {
    int fd;
    char *file = "newfile.txt";

    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC,
              S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);
    if (fd == -1) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    // Do yout operations here

    close(fd);

    return 0;
}
