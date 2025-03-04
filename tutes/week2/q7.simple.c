#include <stdio.h>

int main(void) {

    int x = 24;
loop_condition:
    if (x >= 42) goto loop_end
    // bge $t0, 42, loop_end
    printf("%d\n", x);
    x += 3
    goto loop_condition



loop_end
    return 0;
}