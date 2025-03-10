#include <stdio.h>

int max(int array[], int length) {
    // 
    int first_element = array[0];
    if (length == 1) {
        // Handle the base-case of the recursion, at the end of the array.
        return first_element;
    } else {
        // Recurse on the rest of the array.
        // Finds the largest element after first_element in the array.
        int max_so_far = max(&array[1], length - 1);

        // Compare this element with the largest element after it in the array.
        if (first_element > max_so_far) {
            max_so_far = first_element;
        }
        return max_so_far;
    }
}

int main() {
    int array = {1, 2, 5, 4};
    printf("%d\n", max(array, 4));
}