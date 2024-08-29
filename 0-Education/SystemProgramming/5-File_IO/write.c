#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int fd;
    ssize_t ret, nr;
    size_t len;
    char *buf = "This is an example of writing data to a file in chunks.";
    len = strlen(buf);

    fd = open("output_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    while (len != 0 && (ret = write(fd, buf, len)) != 0) {
        if (ret == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("Error writing to file");
                break;
            }
        }

        len -= ret;
        buf += ret;
    }

    close(fd);

    return 0;
}
