	.text
FLAG_ROWS = 6
FLAG_COLS = 12
main:

	li	$t0, 0	#row = 0
main__for_loop_cond:
	bge	$t0, FLAG_ROWS, main__for_loop_end

	li	$t1, 0	#col = 0
main__inner_for_cond:
	bge	$t1, FLAG_COLS, main__inner_for_end

	#find flag[row][col]
	# rows * num_cols + cols
	#   $t0 *   12    + $t1

	mul	$t2, $t0, FLAG_COLS
	add	$t2, $t2, $t1

	#multiply by offset
	mul	$t2, $t2, 1
	
	#add base address
	add	$t2, $t2, flag


	#get the value
	lb	$t3, ($t2)


	li	$v0, 11
	move	$a0, $t3
	syscall

	addi	$t1, $t1, 1
	b	main__inner_for_cond
main__inner_for_end:
	li	$v0, 11
	li	$a0, '\n'
	syscall

	addi	$t0, $t0, 1
	b	main__for_loop_cond
main__for_loop_end:
	jr	$ra






	.data
flag:
    .byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte	'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte	'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    .byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    .byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'