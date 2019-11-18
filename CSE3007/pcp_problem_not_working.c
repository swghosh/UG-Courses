#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

struct semaphore {
    int tracker;
};
#define SEMAPHORE struct semaphore

void sem_init(SEMAPHORE *s, int value) {
    s->tracker = value;
}
void sem_wait(SEMAPHORE *s) {
    while(s->tracker <= 0);
    --(s->tracker);
}
void sem_signal(SEMAPHORE *s) {
    ++(s->tracker);
}

#define BUFFER_SIZE 1

// producer()
// while(true) {
//     sem_wait(mutex)
//     sem_wait(empty)

//     // critical section

//     sem_signal(full)
//     sem_signal(mutex)
// }

// consumer() 
// while(true) {
//    sem_wait(mutex)
//    sem_wait(full)
//    sem_signal(empty)

//    // critical section

//    sem_signal(mutex)
// }

SEMAPHORE mutex, full, empty;
char buffer[BUFFER_SIZE];
int top = -1;

void *producer(void*);
void *consumer(void*);

int get_random(int limit) {
    float x = (float) rand();
    x = x / RAND_MAX;
    x = x * limit;
    return (int)x;
}

int main() {    
    sem_init(&mutex, 1);
    sem_init(&full, 0);
    sem_init(&empty, BUFFER_SIZE);

    pthread_t prod_id, cons_id; 
    pthread_create(&prod_id, NULL, producer, NULL);
    pthread_create(&cons_id, NULL, consumer, NULL);

    pthread_join(&prod_id, NULL);
    pthread_join(&cons_id, NULL);

    return 0;
}

void *producer(void *vargp) {
    int value;
    while(true) {
        sem_wait(&mutex);
        sem_wait(&empty);

        // critical section
        value = get_random(100);
        printf("Producing Value: %d\n", value);
        buffer[++top] = value;

        sem_signal(&full);
        sem_signal(&mutex);

        value = get_random(5);
        printf("Sleeping %d seconds...\n", value);
        sleep(value);
    }
    return NULL;
}

void *consumer(void *vargp) {
    int value;
    while(true) {
        sem_wait(&full);
        sem_wait(&mutex);

        // critical section
        value = buffer[top--];
        printf("Consuming Value: %d \n", value);

        sem_signal(&mutex);
        sem_signal(&empty);

        value = get_random(5);
        printf("Sleeping %d seconds...\n", value);
        sleep(value);
    }
    return NULL;
}