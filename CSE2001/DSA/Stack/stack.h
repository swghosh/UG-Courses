//
//  stack.h
//  Stack
//
//  Created by Swarup Ghosh on 25/08/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#ifndef stack_h

/* Xcode generated define for include header once */
#define stack_h

#include <stdio.h>
#include <limits.h>

#define STACK_CAPACITY 100

struct stack {
    int elements[STACK_CAPACITY];
    int top;
};

#define STACK struct stack

void init(STACK *stack);

void push(STACK *stack, int element);

int pop(STACK *stack);

void traversePrint(STACK *stack);

#endif /* stack_h */
