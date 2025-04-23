#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int utf8_size(char byte) {
    int mask_1 = 0b10000000;
    int mask_2 = 0b11100000;
    int mask_3 = 0b11110000;
    int mask_4 = 0b11111000;

    if ((byte & mask_1) != mask_1) {
        return 1;
    } else if ((byte & mask_2) != mask_2) {
        return 2;
    } else if ((byte & mask_3) != mask_3) {
        return 3;
    } else if ((byte & mask_4) != mask_4) {
        return 4;
    }
    return 0;

}

//takes in a string from the command line and counts how many UTF-8 characters there are.
int main(int argc, char* argv[]) {
    char *str = argv[1];
    int byte_counter = 0;
    int chars_encountered = 0;
    while (byte_counter < strlen(str)) {
        //determine the size of the codepoint
        int size = utf8_size(str[byte_counter]);
        chars_encountered += 1;
        byte_counter += size;

        // skip that many bytes in the string.
    }
    printf("%d\n", chars_encountered);
}