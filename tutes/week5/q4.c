#include <stdio.h>
#include <stdint.h>

int main() {
    
    uint32_t number = 0b00000000000001011010000000000000; 
     //                 00000000000001111110000000000000
    // 13 + 6 + 13 = 32
    //expected output: 101101

    //READ the SIX middle bits.
    //we want  mask of size 6. in the middle
    //READ = and operation.

    uint32_t mask = 0b111111;
    mask = mask << 13;

    uint32_t output = mask & number;
    output >>= 13;

    printf("%b\n", output);

    

    return 0;


}