        .text
#our code goes here
SQUARE_MAX = 46340

main:
        # x = $t0, y = $t1

        #printf("Enter a number: ")
        li	$v0, 4
        la	$a0, number
        syscall

        # scanf("%d", &x);
        li	$v0, 5
        syscall

        move	$t0, $v0

        #if ( x < square_max)
        ble     $t0, SQUARE_MAX, main__else

        #printf()
        li	$v0, 4
        la	$a0, too_big
        syscall
        ###
        
main__else:
        mul	$t1, $t0, $t0

        #printf("%d",y)
        li	$v0, 1
        move	$a0, $t1
        syscall

        #printf("\n")
        li	$v0, 11
        li	$a0, '\n'
        syscall


main__else_end:
        li	$v0, 0
        jr	$ra

        .data
# string literals + global variables
number:
        .asciiz "Enter a number: "
too_big:
        .asciiz "square too big for 32 bits\n"