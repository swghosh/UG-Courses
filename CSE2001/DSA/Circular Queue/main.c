//
//  main.c
//  Circular Queue
//
//  Created by Swarup Ghosh on 12/09/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "cqueue.h"

int main() {
    CIRCULARQUEUE cqueue;
    init(&cqueue);
    
    int choice, element;
    
    puts("Circular Queue");
    puts("---------------------");
    puts("|No.\t|Choice\t\t|");
    puts("--------------------");
    puts("|1\t\t|Enqueue\t|");
    puts("|2\t\t|Dequeue\t|");
    puts("|3\t\t|Print\t\t|");
    puts("|4\t\t|Exit\t\t|");
    puts("---------------------");
    
    while(true) {
        printf("Specify choice (integer 1-4, expected) -> ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Specify element to enqueue (integer expected) ->");
                scanf("%d", &element);
                printf("Enqueuing element, %d.\n", element);
                enqueue(&cqueue, element);
                break;
            case 2:
                element = dequeue(&cqueue);
                printf((element != INT_MIN) ? "Dequeuing element done (%d).\n" : "Dequeuing element failed.\n", element);
                break;
            case 3:
                puts("Queue contains: ");
                traversePrint(&cqueue);
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
