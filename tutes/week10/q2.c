// Write a C program, now.c, which prints the following information:

// The current date.
// The current time.
// The current user.
// The current hostname.
// The current working directory.

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
int main() {

    pid_t pid;
    pid_t pid2;
    char *ls_argv[3] = {"date", "+%d-%m-%Y", NULL};
    posix_spawn(&pid, "/bin/date", NULL, NULL, ls_argv, environ);
    char *args[3] = {"date", "+%T", NULL};
    posix_spawn(&pid2, "/bin/date", NULL, NULL, args, environ);
    int spawn_exit_status;
    if (waitpid(pid, &spawn_exit_status, 0) == -1) {
        perror("waitpid");
        exit(1);
    }
    if (waitpid(pid2, &spawn_exit_status, 0) == -1) {
        perror("waitpid");
        exit(1);
    }


    



    return 0;
}