#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

//recurse-sample.c: a file that recurses through a directory and prints out permissions and filenames of all files with "hello" in it's name.

// part 0: get and print out current directory pathname.
// part 1: print out all files in current directory.
// part 2: recurse through all subdirectories and print out pathnames.
// part 3: only print out pathnames with "hello" in the filename.
// part 4: print out the permissions of these files.

int recurse(char *pathname) {
   // look through all files in current directories
    //readdir loop
    DIR *dirp = opendir(pathname);
    if (dirp == NULL) {
        perror(pathname);
        exit(1);
    }

    struct dirent *de;
    //de->d_name;
    //de->d_inode;
    struct stat s;
    while ((de = readdir(dirp)) != NULL) {
        if (!strcmp(de->d_name, ".") | !strcmp(de->d_name, "..") ) {
            continue;
        }

        char *new_path = malloc(strlen(pathname) + strlen(de->d_name) + 2);
        sprintf(new_path, "%s/%s", pathname, de->d_name);
        stat(new_path, &s);

        if((s.st_mode & S_IFMT) == S_IFDIR) {
            // printf("recursing into %s\n", new_path);
            recurse(new_path);
        }
        mode_t perms = s.st_mode;
        if(strstr(new_path, "lorem") != NULL) {
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
            printf(" ");
            printf("%s\n", new_path);
        }
        free(new_path);
    }

    return 0;

   // if the file is a directory
        //recurse into it.
}

int main() {
    char *current = getenv("PWD");
    // printf("%s\n", current);
    struct stat a;
    printf("%s\n", a.st_size);
    recurse(current);

}



