//
//  stack.c
//  Stack
//
//  Created by Swarup Ghosh on 25/08/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "stack.h"

void push(STACK *stack, int element) {
    if((*stack).top + 1 == STACK_CAPACITY) {
        printf("Stack Overflow Error.");
        return;
    }
    (*stack).elements[++(*stack).top] = element;
}

int pop(STACK *stack) {
    if((*stack).top == -1) {
        printf("Stack Underflow Error.");
        return INT_MIN;
    }
    return (*stack).elements[(*stack).top--];
}

void traversePrint(STACK *stack) {
    int iterIndex;
    for(iterIndex = 0; iterIndex <= (*stack).top; iterIndex++) {
        printf("%d | ", (*stack).elements[iterIndex]);
    }
}
