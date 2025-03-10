	.text
main:
	push	$ra   #pushed to stack
	#inputs go in a registers, starting in order
	#from a0
	la	$a0, array
	li	$a1, 4
	jal	max
	#ra gets set to here!!!

	#output comes from $v0
	move	$a0, $v0
	li	$v0, 1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

	pop	$ra	#get it back
	jr	$ra

max:
    # Frame:    [...]   <-- FILL THESE OUT!
    # Uses:     [...]
    # Clobbers: [...]
    #
    # Locals:           <-- FILL THIS OUT!
    #   - ...
    #
    # Structure:        <-- FILL THIS OUT!
    #   max
    #   -> [prologue]
    #       -> body
    #   -> [epilogue]

    #a0 = array
    #a1 = int (4)
max__prologue:
	begin
	push	$ra
	push	$s0
max__body:
	#first_element = $s0
	lw	$s0, ($a0)
	bne	$a1, 1, max__else
	
	#return
	move	$v0, $s0
	b	max__epilogue
max__else:

	#call max
	#&array[1]
	la	$t0, array
	addi	$a0, $t0, 4

	#length - 1
	addi	$a1, $a1, -1
	jal	max
	#output of max is in $v0

	move	$t1, $v0
	#max_so_Far is in $t1
max__inner_if:
	ble	$s0, $t1, max__inner_if_end
	move	$t1, $s0
max__inner_if_end:
	#return
	move	$v0, $t1
	b	max__epilogue

max__epilogue:
	pop	$s0
	pop	$ra
	end
	jr	$ra

	.data
array:
	.word	1, 2, 5, 4