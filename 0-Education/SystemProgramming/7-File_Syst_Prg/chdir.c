#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *swd;
    
    if (!(swd = getcwd(NULL, 0))) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    if (chdir("some_other_dir")) {
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    // Do your operation, here

    if (chdir(swd)) {
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    free(swd);
    return 0;
}
