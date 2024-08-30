#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int find_file_in_dir(const char *path, const char *file) {
    struct dirent *entry;
    int ret = 1;
    DIR *dir;
    
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1; // Indicate failure to open directory
    }

    errno = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, file) == 0) {
            ret = 0;
            break;
        }
    }
    
    if (errno) {
        perror("readdir");
    }

    closedir(dir);
    return ret;
}
