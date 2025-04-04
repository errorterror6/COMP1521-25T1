Assume that the following hexadecimal values are
 16-bit twos-complement. 
 Convert each to the corresponding decimal value. 

0x1234
0b 0 001 0010 0011 0100
1 * 16^3 + 2 * 16^2 + 3 * 16^1 + 4 * 16^0
 = 4660 

0xffff

- number = 0b 1111 1111 1111 1111
+ number = two compliment(0b 1111 1111 1111 1111)
//we want to take the two's compliment
0b 1111 1111 1111 1111
//1. take the not
0b 0000 0000 0000 0000
//2. add 1
0b 0000 0000 0000 0001 = 1
therefore, 0xFFFF = -1


0x8000 
0b 1000 0000 0000 0000    //we defined this as neg
//two's compliment
//not
0b 0111 1111 1111 1111
//add 1
0b 1000 0000 0000 0000   //we treat this as positive
= -2^15
