	.text

sum:
	# $a0: value
sum__prologue:
	begin
	push	$ra
	push	$s0
	push	$s1
sum__body:
	li	$s0, 5
	
	move	$a1, $a0
	move	$a0, $s0
	jal	max

	#output k is in $v0
	move	$s1,	$v0
	jal	get_num
	#j is in $v0

	li	$s1, 5

	add	$v0, $v0, $s1
	add	$v0, $v0, $s0
	

sum__epilogue:
	pop	$s1
	pop	$s0
	pop	$ra
	end
	jr	$ra







	.data

max:
get_num: