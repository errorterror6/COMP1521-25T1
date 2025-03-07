Address       Data Definition
0x10010000    aa:  .word 42
0x10010004    bb:  .word 666
0x10010008    cc:  .word 1
0x1001000C         .word 3
0x10010010         .word 5
0x10010014         .word 7

c)
lb   $t0, bb
#will not break
# 0x 00 00 02 9A
# 0x 9A 02 00 00

#but your code will be incorrect at "random" times

h)
la   $t1, cc

lw   $t0, 2($t1)

# it will tell you you broke it.


a) la   $t0, aa
0x10010000

b) lw   $t0, bb
666


g) 
li   $t1, 8
lw   $t0, cc($t1)

5



