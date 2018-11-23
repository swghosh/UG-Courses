//
//  priorityqueue.h
//  Priority Queue
//
//  Created by Swarup Ghosh on 23/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#ifndef priorityqueue_h
#define priorityqueue_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct dNode {
    int data, priority;
    struct dNode *previous, *next;
};
#define NODE struct dNode

struct pQueue {
    NODE *start, *end, *highestPriority;
};
#define PQUEUE struct pQueue

void init(PQUEUE *q);
void enqueue(PQUEUE *q, int data, int priority);
int dequeue(PQUEUE *q);
void traversePrint(PQUEUE *q);

NODE *createNode(int data, int priority);
NODE *highestPriority(PQUEUE *q);

#endif /* priorityqueue_h */
