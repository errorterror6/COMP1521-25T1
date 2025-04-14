#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

// part 0: get current directory.
// part 1: list out the path for all files with "hello" in it's name in sample.
// part 2: print out the permissions of these files.

int recurse(char *current_path);

int main() {
    char *current_path = getenv("PWD");
    printf("%s\n", current_path);
    recurse(current_path);
    return 0;
}

int recurse(char *current_path) {
    // opens DIR pointer
    DIR *dirp = opendir(current_path);
    if (dirp == NULL) {
        perror(current_path);
        exit(1);
    }

    struct dirent *de;
    //loops through all files in DIR, populating struct direct de.
    while ((de = readdir(dirp)) != NULL) {
        printf("%s\n", de->d_name);
    
        //check if is self or parent
        char *self = ".";
        char *parent = "..";
        if (!strcmp(de->d_name, self) || !strcmp(de->d_name, parent)) {
            continue;
        }
        //if directory, recurse into it.
        int new_length = strlen(de->d_name) + strlen(current_path) + 2;
        char *new_path = malloc(new_length * sizeof(char));
        sprintf(new_path, "%s/%s", current_path, de->d_name);
        struct stat s;
        // use lstat
        lstat(new_path, &s);
        mode_t perms = s.st_mode;
        if((perms & S_IFMT) == S_IFDIR) {
            recurse(new_path);
        }
        char *search = "hello";
        if(strstr(de->d_name, search) != NULL) {
            //print out permissions string
            printf("-");
            (perms & S_IRUSR) ? printf("r") : printf("-");
            (perms & S_IWUSR) ? printf("w") : printf("-");
            (perms & S_IXUSR) ? printf("x") : printf("-");
            (perms & S_IRGRP) ? printf("r") : printf("-");
            (perms & S_IWGRP) ? printf("w") : printf("-");
            (perms & S_IXGRP) ? printf("x") : printf("-");
            (perms & S_IROTH) ? printf("r") : printf("-");
            (perms & S_IWOTH) ? printf("w") : printf("-");
            (perms & S_IXOTH) ? printf("x") : printf("-");

            //print out path
            printf(" %s\n", new_path);
        }
    }

    return 0;
}

if (s.st_mode & S_IRUSR)         {printf(“user has read permission”);}
if ((perms & S_IFMT) == S_IFDIR) {printf(“This file is a directory!!”);}