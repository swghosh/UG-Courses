//
//  cqueue.c
//  Circular Queue
//
//  Created by Swarup Ghosh on 12/09/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "cqueue.h"

void init(CIRCULARQUEUE *cqueue) {
    cqueue->front = cqueue->rear = -1;
}

void enqueue(CIRCULARQUEUE *cqueue, int element) {
    if(cqueue->rear + 1 == cqueue->front || (cqueue->front == 0 && cqueue->rear == QUEUE_CAPACITY - 1)) {
        fprintf(stderr, "Circular Queue Overflow Error.\n");
        return;
    }
    else {
        if(cqueue->front == -1 && cqueue->rear == -1) {
            cqueue->front = cqueue->rear = 0;
        }
        else if(cqueue->rear == QUEUE_CAPACITY - 1) {
            cqueue->rear = 0;
        }
        else {
            cqueue->rear += 1;
        }
        cqueue->elements[cqueue->rear] = element;
    }
}

int dequeue(CIRCULARQUEUE *cqueue) {
    int element;
    if(cqueue->front == -1 && cqueue->rear == -1) {
        fprintf(stderr, "Circular Queue Underflow Error.\n");
        return INT_MIN;
    }
    else {
        element = cqueue->elements[cqueue->front];
        if(cqueue->front == cqueue->rear) {
            cqueue->front = cqueue->rear = -1;
        }
        else if(cqueue->front == QUEUE_CAPACITY - 1) {
            cqueue->front = 0;
        }
        else {
            cqueue->front += 1;
        }
        return element;
    }
}

void traversePrint(CIRCULARQUEUE *cqueue) {
    int iterIndex;
    
    // empty queue condition
    if(cqueue->front == -1 && cqueue->rear == -1) {
        puts("");
    }
    else {
        if(cqueue->front <= cqueue->rear) {
            for(iterIndex = cqueue->front; iterIndex <= cqueue->rear; iterIndex++) {
                printf("%d | ", cqueue->elements[iterIndex]);
            }
        }
        else {
            for(iterIndex = cqueue->front; iterIndex < QUEUE_CAPACITY; iterIndex++) {
                printf("%d | ", cqueue->elements[iterIndex]);
            }
            for(iterIndex = 0; iterIndex <= cqueue->rear; iterIndex++) {
                printf("%d | ", cqueue->elements[iterIndex]);
            }
        }
        puts("");
    }
}
