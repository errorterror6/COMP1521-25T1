Address       Data Definition
0x10010000    aa:  .word 42
0x10010004    bb:  .word 666      00 00 0x xx
0x10010008    cc:  .word 1
0x1001000C         .word 3
0x10010010         .word 5
0x10010014         .word 7
# What address will be calculated, and what value will be loaded into register $t0, after each of the following statements (or pairs of statements)? 
'

la   $t1, cc
lw   $t0, 2($t1)	#cc + 2
#emulator/compiler breaks


'
la   $t0, aa       
0x10010000

lw   $t0, bb
666

lb   $t0, bb
#depends on your computer!!
#please check your types don't do this!!
#compiler won't break, but will cause hard to detect bugs.

lw   $t0, aa+4
666

la   $t1, cc
lw   $t0, ($t1)
1

la   $t1, cc
lw   $t0, 8($t1)   #cc + 8
5


li   $t1, 8
lw   $t0, cc($t1)   #cc + 8
5



