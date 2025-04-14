#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int utf8_size(char byte) {
    uint32_t mask_0 = 0b10000000;
    uint32_t mask_1 = 0b11100000;
    uint32_t mask_2 = 0b11110000;
    uint32_t mask_3 = 0b11111000;

    if ((mask_0 & byte) != mask_0) {
        return 1;
    } else if ((mask_1 & byte) != mask_1) {
        return 2;
    } else if ((mask_2 & byte) != mask_2) {
        return 3;
    } else if ((mask_3 & byte) != mask_3) {
        return 4;
    }
    return 0;
}

//takes in a string from the command line and counts how many UTF-8 characters there are.
int main(int argc, char* argv[]) {
    char *str = argv[1];
    int str_len = strlen(str);
    //in a loop
    int bytes = 0;
    int codepoints = 0;
    while (bytes < str_len) {
        //determine how many bytes our utf-8 character is
        if(str[bytes] == '\0') {
            break;
        }
        int size = utf8_size(str[bytes]);
        //skip that many bytes
        bytes += size;
        codepoints ++;


    }
    printf("there were %d objects found.\n", codepoints);

    return 0;
}