//
//  queuelist.h
//  Queue List
//
//  Created by Swarup Ghosh on 26/09/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#ifndef queuelist_h
/* Xcode generated define, for inclusion only once */
#define queuelist_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int value;
    struct node *next;
};
#define NODE struct node

struct queueList {
    NODE *start;
    NODE *tail;
};
#define QUEUELIST struct queueList
#define QUEUE struct queueList

NODE *createNode(int newValue);

void init(QUEUE *queue);
void enqueue(QUEUE *queue, int newValue);
int dequeue(QUEUE *queue);
void traversePrint(QUEUE *queue);

#endif /* queuelist_h */
