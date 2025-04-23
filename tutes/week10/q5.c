#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

// Write a C program that creates a thread that infinitely prints some message 
// provided by main (eg. "Hello\n"), while the main (default) thread 
// infinitely prints a different message (eg. "there!\n"). 

void *thread(void *message) {
    while (true) {
        printf("%s", (char *)message);
        sleep(2);
    }
}

int main() {
    //spawn our thread
    char *message = "hello\n";
    pthread_t thread_id;
    pthread_create(
        &thread_id,
        NULL,
        thread,
        message
    );

    while (true) {
        printf("there\n");
        sleep(1);
    }



}