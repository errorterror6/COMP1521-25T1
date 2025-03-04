// For those interested, this is an implementation of elementary cellular
// automata: https://en.wikipedia.org/wiki/Elementary_cellular_automaton
// Not only does it produce interesting and complex outptut from a relatively
// simple description, at least one 'rule' is capable of universal computation.
//
// Written 2024-02-03 by Xavier Cooney

#include <stdio.h>

#define WIDTH 70

int main(void) {
    char arr[2 * WIDTH + 5] = {0};
    char *prev = arr + 1;
    char *next = prev + WIDTH + 3;

    fgets(prev, WIDTH + 2, stdin);

    int height;
    scanf("%d", &height);

    int rule;
    scanf("%d", &rule);

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < WIDTH; ++col) {
            int left = prev[col - 1] > '0';
            int middle = prev[col] > '0';
            int right = prev[col + 1] > '0';
            int index = left * 4 + middle * 2 + right;
            int shifted = rule;
            while (index > 0) {
                shifted /= 2;
                index--;
            }
            next[col] = 32 + (shifted % 2) * 32;
            putchar(next[col]);
        }
        putchar('\n');
        char *temp = prev;
        prev = next;
        next = temp;
    }
}