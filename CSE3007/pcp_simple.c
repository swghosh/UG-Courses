#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

#define BUFFER_SIZE 5

SEMAPHORE mutex, full, empty;
int x = 0;

void producer() {
    if(mutex.tracker == 1 && empty.tracker != 0) {
        sem_wait(&mutex);
        sem_wait(&empty);
    
        x += 2;
        printf("Producer produced %d. \n", x);

        sem_signal(&full);
        sem_signal(&mutex);
    } 
    else {
        printf("Buffer is full, cannot produce. \n");
    }    
}

void consumer(){
    if(mutex.tracker == 1 && full.tracker != 0) {
        sem_wait(&full);
        sem_wait(&mutex);
        
        printf("Consumer consumed an item %d. \n", x);
        x -= 2;

        sem_signal(&mutex);
        sem_signal(&empty);
    } 
    else {	
        printf("Buffer is empty, cannot consume. \n");
    }
}


int main() {
    int choice;

    sem_init(&mutex, 1);
    sem_init(&full, 0);
    sem_init(&empty, BUFFER_SIZE);
    
    printf("Buffer size is preset to %d.\n", BUFFER_SIZE);

    while(true) {
        printf("Options.. (1) Produce; (2) Consume; (3) Exit\n");
        printf("Choice (integer expected) -> ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                producer();
                break;
            case 2: 
                consumer();
                break;		
            default:
                return 0;
        }
        printf("\n"); 
    }
    return 0;
}