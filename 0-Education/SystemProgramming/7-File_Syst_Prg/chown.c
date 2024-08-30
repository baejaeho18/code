#include <stdio.h>
#include <unistd.h>
#include <grp.h>

int main() {
    struct group *gr;
    int ret;

    gr = getgrnam("prof");
    if (gr == NULL) {
        perror("getgrnam");
        return 1;
    }

    ret = chown("chown-test.txt", -1, gr->gr_gid);
    if (ret != 0) {
        perror("chown");
        return 1;
    }

    return 0;
}
