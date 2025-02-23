	.text
SQUARE_MAX = 46340

main:
	# represent local variables as registers
	#x = $t0, y = $t1


	#
	la	$a0, print_string
	li	$v0, 4
	syscall

	li	$v0, 5
	syscall
	#now input is in $v0

	move	$t0, $v0

	#opposite condition, go to the end
	ble	$t0, SQUARE_MAX, main__else


	li	$v0, 4
	la	$a0, too_big
	syscall

	b 	main__if_end

main__else:
	mul	$t1, $t0, $t0

	li	$v0, 1
	move	$a0, $t1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

main__if_end:

	li	$v0, 0
	jr	$ra

	.data
#string literals must be from the .data section
print_string:
	.asciiz	"Enter a number: "
too_big:
	.asciiz "square too big for 32 bits\n"

