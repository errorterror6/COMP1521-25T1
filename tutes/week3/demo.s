	.text
main:
	lw	$a0, answer

	li	$v0, 1
	syscall

	li	$a0, '\n'
	li	$v0, 11
	syscall

	jr	$ra

	.data
x:
	.byte   1
answer:
	.byte   1, 2, 3, 4