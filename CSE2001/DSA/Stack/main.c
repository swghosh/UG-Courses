//
//  main.c
//  Stack
//
//  Created by Swarup Ghosh on 24/08/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

int main(void) {
    STACK stack;
    init(&stack);
    
    int choice, element;
    
    puts("-----------------");
    puts("|No.\t|Choice\t|");
    puts("-----------------");
    puts("|1\t\t|Push\t|");
    puts("|2\t\t|Pop\t|");
    puts("|3\t\t|Print\t|");
    puts("|4\t\t|Exit\t|");
    puts("-----------------");
    
    while(true) {
        printf("Specify choice (integer 1-4, expected) -> ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Specify element to push (integer expected) ->");
                scanf("%d", &element);
                push(&stack, element);
                printf("Element pushed. (%d)\n", element);
                break;
            case 2:
                element = pop(&stack);
                printf("Element popped. (%d)\n", element);
                break;
            case 3:
                puts("Stack contains: ");
                traversePrint(&stack);
                break;
            case 4:
                exit(0);
                break;
                
            default:
                puts("Invalid choice, please retry.");
                break;
        }
    }
    
    return 0;
    
}
