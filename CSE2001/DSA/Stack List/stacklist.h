//
//  stacklist.h
//  Stack List
//
//  Created by Swarup Ghosh on 26/09/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#ifndef stacklist_h
#define stacklist_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int value;
    struct node *next;
};
#define NODE struct node

struct stackList {
    NODE *start;
    NODE *tail;
};
#define STACKLIST struct stackList
#define STACK struct stackList

NODE *createNode(int value);

void init(STACK *stack);
void push(STACK *stack, int newValue);
int pop(STACK *stack);
void traversePrint(STACK *stack);

#endif /* stacklist_h */
