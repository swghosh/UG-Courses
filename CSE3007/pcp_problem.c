#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

struct semaphore {
    int tracker;
};
#define SEMAPHORE struct semaphore

void init(SEMAPHORE *s, int value) {
    s->tracker = value;
}
void wait(SEMAPHORE *s) {
    while(s->tracker <= 0);
    --(s->tracker);
}
void signal(SEMAPHORE *s) {
    ++(s->tracker);
}

#define BUFFER_SIZE 10
// producer()
// while(true) {
//     wait(mutex)
//     wait(empty)

//     // critical section

//     signal(full)
//     signal(mutex)
// }

// consumer() 
// while(true) {
//    wait(mutex)
//    wait(full)
//    signal(empty)

//    // critical section

//    signal(mutex)
// }

SEMAPHORE mutex, full, empty;

int main() {
    pid_t pid;
    
    init(&mutex, 1);
    init(&full, 0);
    init(&empty, BUFFER_SIZE);

    pid = fork();
    if(pid == 0) {
        producer();
    }
    else {
        consumer();
    }
    return 0;
}

void producer() {
    while(true) {
        wait(&mutex);
        wait(&empty);

        signal(&full);
        signal(&mutex);
    }
}

void consumer() {
    while(true) {
        
    }
}