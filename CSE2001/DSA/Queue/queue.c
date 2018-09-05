//
//  queue.c
//  Queue
//
//  Created by Swarup Ghosh on 05/09/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "queue.h"

void init(QUEUE *queue) {
    (*queue).front = (*queue).rear = -1;
}

void enqueue(QUEUE *queue, int element) {
    if((*queue).rear + 1 == QUEUE_CAPACITY) {
        fprintf(stderr, "Queue Overflow Error.\n");
        return;
    }
    else if((*queue).front == -1 && (*queue).rear == -1) {
        (*queue).front = (*queue).rear = 0;
        (*queue).elements[(*queue).rear] = element;
    }
    else {
        (*queue).elements[++(*queue).rear] = element;
    }
}

int dequeue(QUEUE *queue) {
    int element;
    if((*queue).front == -1 && (*queue).rear == -1) {
        fprintf(stderr, "Queue Underflow Error.\n");
        element = INT_MIN;
    }
    else if((*queue).front == (*queue).rear) {
        element = (*queue).elements[(*queue).rear];
        (*queue).front = (*queue).rear = -1;
    }
    else {
        element = (*queue).elements[(*queue).front++];
    }
    return element;
}

void traversePrint(QUEUE *queue) {
    int iterIndex;
    // applying ternary condition for empty check in initialisation itself
    for(iterIndex = ((*queue).front == -1) ? 0 : (*queue).front; iterIndex <= (*queue).rear; iterIndex++) {
        printf("%d | ", (*queue).elements[iterIndex]);
    }
    puts("");
}
