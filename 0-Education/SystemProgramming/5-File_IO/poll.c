#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <errno.h>

#define TIMEOUT 5000  // 5 seconds

int main() {
    int fd;
    struct pollfd fds[1];
    int ret;

    fd = open("example_file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fds[0].fd = fd;              
    fds[0].events = POLLIN;       

    ret = poll(fds, 1, TIMEOUT);  
    
    if (ret == -1) {
        perror("poll error");
        close(fd);
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Timeout occurred! No data within 5 seconds.\n");
    } else {
        if (fds[0].revents & POLLIN) {
            printf("Data is available to read!\n");
        }
    }

    close(fd);

    return 0;
}
