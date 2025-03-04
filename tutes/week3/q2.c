.data
0x10010020
a:  .word   42   //use this for ints that are initialized
0x10010024
b:  .space  4     // use for any uninitialized values
0x10010028
c:  .asciiz "abcde"   //has a hidden null terminator -> 6 bytes
0x1001002D                  0123456789ABCEDF
z:  .space  1
    .align  2
0X10010030  ##WRONG
d:  .byte   1, 2, 3, 4
//4 bytes next to each other
0x10010034
e:  .word   1, 2, 3, 4
//4 "ints" next to each  -> +16
0x10010044
f:  .space  1