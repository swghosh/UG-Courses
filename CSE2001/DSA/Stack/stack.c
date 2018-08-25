//
//  stack.c
//  Stack
//
//  Created by Swarup Ghosh on 25/08/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "stack.h"

void init(STACK *stack) {
    (*stack).top = -1;
}

void push(STACK *stack, int element) {
    if((*stack).top + 1 == STACK_CAPACITY) {
        fprintf(stderr, "Stack Overflow Error.\n");
        return;
    }
    (*stack).elements[++(*stack).top] = element;
}

int pop(STACK *stack) {
    if((*stack).top == -1) {
        fprintf(stderr, "Stack Underflow Error.\n");
        return INT_MIN;
    }
    return (*stack).elements[(*stack).top--];
}

void traversePrint(STACK *stack) {
    int iterIndex;
    for(iterIndex = 0; iterIndex <= (*stack).top; iterIndex++) {
        printf("%d | ", (*stack).elements[iterIndex]);
    }
    puts("");
}
