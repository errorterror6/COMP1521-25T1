#include <stdio.h>

int main(void) {
    int number, i;

    printf("Enter a number: ");
    scanf("%d", &number);

    i = 1;
main__loop_cond:
    if (i > number) goto main__loop_end;
        printf("%d\n", i);
        i = i + 1;
    goto main__loop_cond;

main__loop_end:
    return 0;
}