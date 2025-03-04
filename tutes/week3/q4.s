Address       Data Definition
0x10010000    aa:  .word 42
0x10010004    bb:  .word 666       00 00 0x xx
				   xx x0 00 00
0x10010008    cc:  .word 1
0x1001000C         .word 3
0x10010010         .word 5
0x10010014         .word 7

char 	number = 5;
number:
	.byte 	5

lb	$t0, number



a) la   $t0, aa
$t0 = 0x10010000

b) lw   $t0, bb
$t0 = 666

c) lb   $t0, bb
#partial answer that depends on you machine.
#not complained by the compiler
#very hard to debug.




h) la   $t1, cc
lw   $t0, 2($t1)