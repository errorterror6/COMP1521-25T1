//write characters from an array into a file called test.txt

char array[9] = {'a', 'b', '\0', 'c', 'd', '\0', 'e', 'f', '\0'};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    //open
    FILE *fp = fopen("test1.txt", "r");
    if (fp == NULL) {
        perror("test1.txt");
        exit(1);
    }

    char string[10];

    //read the file using fgets until we can't anymore.
    while (fgets(string, 9, fp) != NULL) {
        printf("one iteration\n");
        printf("read in: %c\n", string[0]);
        printf("read in: %c\n", string[1]);
        printf("read in: %c\n", string[2]);
        printf("read in: %c\n", string[3]);
        printf("read in: %c\n", string[4]);
    }



    //close
    fclose(fp);





    return 0;
}