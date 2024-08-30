#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_LEN 1024

int main() {
    char cwd[BUF_LEN];

    if (!getcwd(cwd, BUF_LEN)) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    printf("cwd = %s\n", cwd);
    return 0;
}
