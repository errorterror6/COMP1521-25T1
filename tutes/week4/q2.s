	.text
FLAG_ROWS = 6
FLAG_COLS = 12

main:
	li	$t0, 0   #row = $t0
main__for_one_start:
	
	bge	$t0, FLAG_ROWS, main__for_one_end

	li	$t1, 0	#col = $t1
main__for_two_start:
	
	bge	$t1, FLAG_COLS, main__for_two_end

	#we need flag[row][col]
	#we need the offset from [row][col]
	# row * num_cols
	mul	$t2, $t0, FLAG_COLS
	# + cols
	add	$t2, $t2, $t1

	#multiple by element size
	mul	$t2, $t2, 1

	#lb from flag + offset.
	lb	$t2, flag($t2)
	#print it out
	li	$v0, 11
	move	$a0, $t2
	syscall

	addi	$t1, $t1, 1    #col ++
	b	main__for_two_start
main__for_two_end:
	#printf("\n")
	li	$v0, 11
	li	$a0, '\n'
	syscall

	addi	$t0, $t0, 1   #row ++
	b	main__for_one_start
main__for_one_end:
	jr	$ra




	.data
flag:
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
	.byte	'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
	.byte	'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#',
	.byte	'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
