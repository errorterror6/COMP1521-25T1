#include <stdio.h>

int main(void) {

    int x = 24;
while_cond:
    if (x >= 42) goto while_end;

    printf("%d\n", x);
    x += 3;
    goto while_cond;

while_end:
    return 0;

}