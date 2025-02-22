#include <stdio.h>

void test_function(int *ptr);

int main(void) {
    int number = 36;
    int* ptr = &number;

    printf("ptr to number: %d\n", ptr);
    printf("*ptr to number: %d\n", *ptr);


    test_function(ptr);
    return 0;
}

void test_function(int* ptr) {
    printf("function: ptr to number: %d\n", ptr);
    printf("function: *ptr to number: %d\n", *ptr);
}
