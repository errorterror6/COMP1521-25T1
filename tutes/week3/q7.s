	.text
	#your code goes here
N_SIZE = 10

main:
	#$t0 = i

	li	$t0, 0
main__while_loop:
	bge	$t0, N_SIZE, main__while_end

	#calculate the address of numbers[i]
	# address = numbers + 4 * i
	la	$t1, numbers
	#4*i
	mul	$t2, $t0, 4
	# numbers + 4*i
	add	$t1, $t1, $t2
	#load in the value of numbers[i]
	lw	$t2, ($t1)
	#$t2 is value of numbers[i], $t1 is numbers[i] address.

	


	# if (numbers[i] < 0) 
	bge	$t2, 0, main__if_end

	#numbers[i] = numbers[i] + 42
	#  sw            lw
	addi	$t2, $t2, 42
	sw	$t2, ($t1)

main__if_end:
	addi	$t0, $t0, 1
	b	main__while_loop
main__while_end:

	jr	$ra
	.data
	#global vars and string literals
numbers:
	.word	0, 1, 2, -3, 4, -5, 6, -7, 8, 9
