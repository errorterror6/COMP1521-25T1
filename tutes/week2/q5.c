#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > SQUARE_MAX) {
        printf("square too big for 32 bits\n"); //27
    } else {
        y = x * x;
        printf("%d\n", y);
    }

    return 0;
}


