//
//  main.c
//  Stack
//
//  Created by Swarup Ghosh on 24/08/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>

#include "stack.h"

int main(void) {
    STACK myStack;
    myStack.top = -1;
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    push(&myStack, 40);
    pop(&myStack);
    traversePrint(&myStack);
    puts("");
    return 0;
}
