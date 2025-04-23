//write characters from an array into a file called test.txt

char array[9] = {'a', 'b', '\0', 'c', 'd', '\0', 'e', 'f', '\0'};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

    //open
    FILE *fp = fopen("test.txt", "a");
    if (fp == NULL) {
        perror("test.txt");
        exit(1);
    }
    // find out the length of the file.
    struct stat s;
    if (stat("test.txt", &s) != 0) {
        perror("test.txt");
        exit(1);
    };

    printf("file size is currently %ld:\n", s.st_size);


    //write to the file.
    //fputc -> 1 byte
    for (int i = 0; i < 5; i++) {
        int ret;
        if((ret = fputc(array[i], fp)) == EOF) {
            fprintf(stderr, "failed to read");
            exit(1);
        };
        
    }
    // //fwrite -> many
    int written = fwrite(array, 1, 4, fp);
    if (written != 4) {
        fprintf(stderr, "fwrite failed");
        exit(1);
    }
    //we expect written to equal 4.



    //close
    fclose(fp);





    return 0;
}