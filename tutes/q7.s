	.text
# this is where our code goes
N_SIZE = 10

main:
	#$t0 = i
	li	$t0, 0

main__loop_cond:
	bge	$t0, N_SIZE, main__loop_end
	#we need to calculate numbers[i] so we can finish this if statement!!
	la	$t1, numbers  #base address

	mul	$t2, $t0, 4		#int array each element is of size 4.
	# add	$t1, $t1, $t2          #total address = numbers + [i]

	lw	$t2, numbers($t2)	#load the value in from the address
	#$t1 is the address of numbers[i], #$t2 is the value of numbers[i]

	bge	$t2, 0, main__loop_if_end

	addi	$t2, $t2, 42
	sw	$t2, ($t1)
	#numbers[i] = numbers[i] + 42
	



main__loop_if_end:
	addi	$t0, $t0, 1
	b 	main__loop_cond
main__loop_end:

	jr	$ra




	.data
# this is where global and string literals go
#and also complex memory structures!!!
numbers:
	.word	0, 1, 2, -3, 4, -5, 6, -7, 8, 9
