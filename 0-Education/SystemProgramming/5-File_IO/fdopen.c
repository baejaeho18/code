#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    FILE *stream;
    int fd;

    fd = open("/home/kid/map.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    stream = fdopen(fd, "r");
    if (stream == NULL) {
        perror("Error converting file descriptor to FILE *");
        close(fd);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stream) != NULL) {
        printf("%s", buffer);
    }

    fclose(stream);

    return 0;
}
