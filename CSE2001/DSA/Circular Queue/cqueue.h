//
//  cqueue.h
//  Circular Queue
//
//  Created by Swarup Ghosh on 12/09/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#ifndef cqueue_h

/* Xcode generated define for include header once */
#define cqueue_h

#include <stdio.h>
#include <limits.h>

// using small capacity so as
// to test the overflow error
// cases properly
// (*) value can be modified
// (*) to higher capacity like 100/1000
// (*) when in actual use
#define QUEUE_CAPACITY 5

struct circularQueue {
    int elements[QUEUE_CAPACITY];
    int front, rear;
};

#define CIRCULARQUEUE struct circularQueue

void init(CIRCULARQUEUE *cqueue);

void enqueue(CIRCULARQUEUE *cqueue, int element);

int dequeue(CIRCULARQUEUE *cqueue);

void traversePrint(CIRCULARQUEUE *cqueue);

#endif /* cqueue_h */
