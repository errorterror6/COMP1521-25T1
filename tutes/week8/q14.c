#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

//lets add group write permission to alpabets

int main() {
    

    //we want to read in our mode
    struct stat s;
    stat("alpabets", &s);
    //get our current permissions
    mode_t current_mode = s.st_mode;

    //we want to add group write permission to the mode
    mode_t new_mode = current_mode | S_IWGRP;

    //change the permissions of alpabets.
    chmod("alpabets", new_mode);


    return 0;
}