//
//  queue.h
//  Queue
//
//  Created by Swarup Ghosh on 05/09/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#ifndef queue_h

/* Xcode generated define for include header once */
#define queue_h

#include <stdio.h>
#include <limits.h>

#define QUEUE_CAPACITY 100

struct queue {
    int elements[QUEUE_CAPACITY];
    int front, rear;
};

#define QUEUE struct queue

void init(QUEUE *queue);

void enqueue(QUEUE *queue, int element);

int dequeue(QUEUE *queue);

void traversePrint(QUEUE *queue);

#endif /* queue_h */
