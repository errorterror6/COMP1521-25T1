#include <stdio.h>

int main() {
    int counter = 0;
    //loop - while there are 
    while (getchar() != EOF) {
        //increment counter
        counter++;
    }
    printf("\n%d\n", counter);
    return 0;
}