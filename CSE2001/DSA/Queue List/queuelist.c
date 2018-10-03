//
//  queuelist.c
//  Queue List
//
//  Created by Swarup Ghosh on 26/09/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "queuelist.h"

NODE *createNode(int newValue) {
    NODE *new = (NODE*) malloc(sizeof(NODE));
    new->value = newValue;
    new->next = NULL;
    return new;
}

void init(QUEUE *queue) {
    queue->start = queue->tail =NULL;
}

void enqueue(QUEUE *queue, int newValue) {
    // when the queue is empty
    if(queue->start == NULL) {
        queue->start = queue->tail = createNode(newValue);
    }
    // when the queue is not empty
    else {
        queue->tail->next = createNode(newValue);
        queue->tail = queue->tail->next;
    }
}

int dequeue(QUEUE *queue) {
    int popValue;
    // when queue is empty
    if(queue->start == NULL) {
        fprintf(stderr, "Queue Underflow Error.");
        return INT_MIN;
    }
    // when queue is not empty
    else {
        popValue = queue->start->value;
        queue->start = queue->start->next;
        return popValue;
    }
}

void traversePrint(QUEUE *queue) {
    NODE *iter;
    if(queue->start == NULL) {
        printf("Queue empty.");
    }
    else {
        iter = queue->start;
        while(iter != NULL) {
            printf("%d -> ", iter->value);
            iter = iter->next;
        }
    }
    puts("");
}
