#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int fd;
    unsigned long word;
    ssize_t nr;

    fd = open("example_file.bin", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    nr = read(fd, &word, sizeof(unsigned long));
    if (nr == -1) {
        perror("Error reading file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (nr < sizeof(unsigned long)) {
        printf("Partial read occurred.\n");
    } else {
        printf("Read %lu bytes into 'word': %lx\n", sizeof(unsigned long), word);
    }

    close(fd);
    
    return 0;
}
