//
//  priorityqueue.c
//  Priority Queue
//
//  Created by Swarup Ghosh on 23/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "priorityqueue.h"

void init(PQUEUE *q) {
    q->start = q->end = q->highestPriority = NULL;
}

NODE *createNode(int data, int priority) {
    NODE *new;
    new = (NODE*) malloc(sizeof(NODE));
    new->data = data;
    new->priority = priority;
    new->previous = new->next = NULL;
    return new;
}

NODE *highestPriority(PQUEUE *q) {
    NODE *iter, *hp = NULL; int highPriority = INT_MIN;
    iter = q->start;
    while(iter != NULL) {
        if(iter->priority > highPriority) {
            highPriority = iter->priority;
            hp = iter;
        }
    }
    return hp;
}

void traversePrint(PQUEUE *q) {
    if(q->start == NULL) {
        printf("Empty queue.\n");
        return;
    }
    NODE *iter;
    iter = q->start;
    while(iter != NULL) {
        printf("%d, priority = %d | ", iter->data, iter->priority);
        iter = iter->next;
    }
    printf("\n");
}

void enqueue(PQUEUE *q, int data, int priority) {
    NODE *new;
    new = createNode(data, priority);
    if(q->start == NULL && q->end == NULL) {
        q->start = q->end = new;
    }
    else {
        q->end->next = new;
        new->previous = q->end;
        q->end = new;
    }
    
    if(q->highestPriority == NULL || new->priority > q->highestPriority->priority) {
        q->highestPriority = new;
    }
}

int dequeue(PQUEUE *q) {
    if(q->highestPriority == NULL) {
        fprintf(stderr, "Dequeue not possible.\n");
        return INT_MIN;
    }
    NODE *left, *right; int data;
    data = q->highestPriority->data;
    
    left = q->highestPriority->previous;
    right = q->highestPriority->next;
    
    left->next = right;
    right->previous = left;
    
    free(q->highestPriority);
    
    q->highestPriority = highestPriority(q);
    return data;
}
