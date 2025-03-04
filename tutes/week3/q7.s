	.text
#code
N_SIZE = 10


main:
	#$t0 = i
	li	$t0, 0

main__loop_cond:
	#while (i < N_SIZE)
	bge	$t0, N_SIZE, main__loop_end

	#calculate numbers[i] address
	# 4 * i
	mul	$t2, $t0, 4
	lw	$t1, numbers($t2)
	#$t1 is the numbers[i] value.
	bge	$t1, 0, main__loop_if_end

	#numbers[i] = numbers[i] + 42
	# sw modification  =     lw (interested in the value)
	addi	$t1, $t1, 42
	sw	$t1, numbers($t2)
main__loop_if_end:
	addi	$t0, $t0, 1
	b	main__loop_cond
main__loop_end:
	jr	$ra
	.data
#global variables, string literals
numbers:
	.word	0, 1, 2, -3, 4, -5, 6, -7, 8, 9