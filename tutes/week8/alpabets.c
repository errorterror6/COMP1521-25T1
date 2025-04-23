// read from a file alphabets.txt and 
//swap the first 13 letters with the last 13 letters.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // open the file for reading
    FILE *fp = fopen("alphabets.txt", "r");
    //if pointer, always check against NULL.
    if (fp == NULL) {
        perror("alphabets.txt");
        exit(1);
    }

    // read in the contents
       //read the first half
    char first[14] = {0};
    int check = fread(first, 1, 13, fp);
    //we expect check == 13.
    if (check != 13) {
        fprintf(stderr, "error reading file.");
        exit(1);
    }

    first[13] = '\0';
       //read the second half
       //my fp is already at character 14.



    char second[14] = {0};
    for (int i = 0; i < 13; i++) {
        second[i] = fgetc(fp);
        if (second[i] == EOF) {
            fprintf(stderr, "fgetc failed");
            exit(1);
        }
    }
    second[13] = '\0';

    fclose(fp);
    //close to allow re-opening for writing

    FILE *fp2 = fopen("alphabets.txt", "w");
    if (fp2 == NULL) {
        perror("alphabets.txt");
        exit(1);
    }
    //swap the contents and write it back into the file
    int written1 = fwrite(second, 1, 13, fp2);
    if (written1 != 13) {
        fprintf(stderr, "fwrite did not work");
        exit(1);
    }

    int written2 = fwrite(first, 1, 13, fp2);
    if (written2 != 13) {
        fprintf(stderr, "fwrite did not work");
    }
    fclose(fp2);
    
    return 0;
}