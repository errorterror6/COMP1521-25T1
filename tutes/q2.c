.data

//0x10010020
a:  .word   42  //this occupies 4 bytes of space!!
//0x10010024
b:  .space  4    // this means allocate 4 bytes of space!!
//0x10010028
c:  .asciiz "abcde"  //5 characters + 1 hidden byte!
//0x1001002D  -> not divisible by 4!!
//0x10010030  -> padded space
d:  .byte 'a'


123456789ABCEDF


x: .half 'b'   -> '2' byte aligned
