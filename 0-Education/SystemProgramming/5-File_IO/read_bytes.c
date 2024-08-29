#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int fd;
    ssize_t ret;
    size_t len;
    char *buf;
    size_t buffer_size = 1024; 

    fd = open("example_file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    buf = (char *)malloc(buffer_size);
    if (buf == NULL) {
        perror("Error allocating memory");
        close(fd);
        exit(EXIT_FAILURE);
    }

    len = buffer_size;

    while (len != 0 && (ret = read(fd, buf, len)) != 0) {
        if (ret == -1) {
            if (errno == EINTR) { 
                continue;
            } else {
                perror("Error reading file");
                break;
            }
        }
        
        printf("Read %zd bytes\n", ret);

        len -= ret; 
        buf += ret;
    }

    free(buf);
    close(fd);

    return 0;
}
