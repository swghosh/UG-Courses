//
//  main.c
//  Queue
//
//  Created by Swarup Ghosh on 05/09/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

int main(int argc, const char * argv[]) {
    QUEUE queue;
    init(&queue);
    
    int choice, element;
    
    puts("-----------------");
    puts("|No.\t|Choice\t\t|");
    puts("-----------------");
    puts("|1\t\t|Enqueue\t|");
    puts("|2\t\t|Dequeue\t|");
    puts("|3\t\t|Print\t\t|");
    puts("|4\t\t|Exit\t\t|");
    puts("-----------------");
    
    while(true) {
        printf("Specify choice (integer 1-4, expected) -> ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Specify element to enqueue (integer expected) ->");
                scanf("%d", &element);
                printf("Enqueuing element, %d.\n", element);
                enqueue(&queue, element);
                break;
            case 2:
                element = dequeue(&queue);
                printf((element != INT_MIN) ? "Dequeuing element done (%d).\n" : "Dequeuing element failed.\n", element);
                break;
            case 3:
                puts("Queue contains: ");
                traversePrint(&queue);
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
