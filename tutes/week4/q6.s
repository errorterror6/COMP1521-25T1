        .text
main:
        push	$ra

        la	$a0, array
        li	$a1, 4
        jal	max

        move	$a0, $v0  #move output of max into a0 for printing
        li	$v0, 1
        syscall

        li	$v0, 11
        li	$a0, '\n'
        syscall


        pop	$ra
        jr	$ra


max:
        #$a0 : array
        #$a1 : length
max__prologue:
        begin
        push	$ra
        push	$s0
max__body:
        lw	$s0, 0($a0)     #int first_element = array[0];
max__if:
        bne	$a1, 1, max__else
        move	$v0, $s0
        j	max__epilogue
max__else:

        addi	$a0, $a0, 4
        addi	$a1, $a1, -1
        jal	max
        #output is in $v0

        move	$t0, $v0        #t0 = max_so_far
max__inner_if:
        ble	$s0, $t0, max__inner_if_end
        move	$t0, $s0
max__inner_if_end:
        move	$v0, $t0


max__epilogue:
        pop	$s0
        pop	$ra
        end
        jr	$ra







        .data
array:
        .word   1, 2, 5, 4