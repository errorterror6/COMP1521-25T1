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
int recurse(char *pathname);

int main() {
    char *current = getenv("PWD");
    // printf("current path: %s\n", current);

    printf("paths found in current directory: \n");

    recurse(current);
}

int recurse(char *pathname) {
    //look through our entire directory
    DIR *dirp = opendir(pathname);
    if (dirp == NULL) {
        perror(pathname);
        exit(1);
    }
    struct dirent *de;
    while ((de = readdir(dirp)) != NULL) {
        // printf("%s\n", de->d_name);


        //skip over . and ..
        char *curr = ".";
        char *parent = "..";
        if (!strcmp(de->d_name, curr) || !strcmp(de->d_name, parent)) {
            continue;
        }

        //if directory,
        struct stat s;

        // piece together new pathname.
        int buffer_len = strlen(pathname) + strlen(de->d_name) + 2;
        char *new_path = malloc(buffer_len * sizeof(char));
        sprintf(new_path, "%s/%s", pathname, de->d_name);

        stat(new_path, &s);
        mode_t perms = s.st_mode;
        if ((perms & S_IFMT) == S_IFDIR) {
            recurse(new_path);
        }
        
        //everythign left here are just regular files
        //print out their names.
        char *search = "hello";
        if(strstr(new_path, search) != NULL) {
            //print out permissions here
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

            //print out our name
            printf("%s\n", new_path);
        }
        


    }
    return 0;

}



// helloworld!!
// world