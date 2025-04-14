#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdint.h>

int main() {
    struct stat s;
    stat("sample", &s);
    // printf("whole mode: %o\n", s.st_mode);

    // only look at last 9
    uint32_t mask = 0777;
    uint32_t perms = s.st_mode;
    perms = perms & mask;


    printf("%o\n", perms);
    // printf("%b\n", perms);
    return 0;
}

