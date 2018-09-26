//
//  stacklist.c
//  Stack List
//
//  Created by Swarup Ghosh on 26/09/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "stacklist.h"

NODE *createNode(int value) {
    NODE *new = (NODE*)malloc(sizeof(NODE));
    new->value = value;
    new->next = NULL;
    return new;
}

// will initialise a
// a stack list with
// start as null
// O(1) complexity

void init(STACK *stack) {
    stack->start = NULL;
}

// will insert elements
// to the end of the stack list
// pointer for tail exists
// therefore, O(1) complexity

void push(STACK *stack, int newValue) {
    // when the stack is empty
    if(stack->start == NULL) {
        stack->start = stack->tail = createNode(newValue);
    }
    // when the stack is not empty
    else {
        stack->tail->next = createNode(newValue);
    }
}

// will delete elements
// from the end of the stack list
// O(n) complexity

int pop(STACK *stack) {
    NODE *iter = NULL; int popValue;
    // when the stack is empty
    if(stack->tail == NULL) {
        fprintf(stderr, "Stack Underflow Error.");
        return INT_MIN;
    }
    // when the stack has exactly one element
    else if(stack->start->next == NULL) {
        popValue = stack->start->value;
        iter = stack->start;
        stack->start = stack->tail = NULL;
        free(iter);
        return popValue;
    }
    // when the stack has more than one element
    else {
        iter = stack->start;
        while(iter->next->next != NULL) {
            iter = iter->next;
        }
        stack->tail = iter;
        popValue = iter->next->value;
        free(iter->next);
        iter->next = NULL;
        return popValue;
    }
}

// prints all items
// present in the stack list
// O(n) complexity

void traversePrint(STACK *stack) {
    NODE *iter = stack->start;
    if(stack->start == NULL) {
        printf("Empty Stack.");
    }
    else {
        while(iter != NULL) {
            printf("%d -> ", iter->value);
            iter = iter->next;
        }
    }
    puts("");
}
