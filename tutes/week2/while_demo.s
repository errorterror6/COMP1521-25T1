	.text
main:
	#let $t0 = i
	li 	$t0, 0
main__loop_cond:
	bge	$t0, 10, main__loop_end
main__loop_body:
	# i am aware this is C code. but I'm lazy and out of space.
	printf("i sure hope i have not made any bugs\n");  
	addi    $t0, $t0, 1
	#make sure to loop back to the condition
	b	main__loop_cond
main__loop_end:
	jr	$ra



