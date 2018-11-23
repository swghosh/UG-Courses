//
//  main.c
//  Priority Queue
//
//  Created by Swarup Ghosh on 23/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>

#include "priorityqueue.h"

int main() {
    PQUEUE q;
    init(&q);
    enqueue(&q, 10, 5);
    enqueue(&q, 20, 200);
    enqueue(&q, 30, 10);
    printf("HIGHEST PRIORITY :%d, priority = %d:\n", q.highestPriority->data, q.highestPriority->priority);
    traversePrint(&q);
    printf("Dequeued: %d.\n", dequeue(&q));
    printf("Dequeued: %d.\n", dequeue(&q));
    printf("Dequeued: %d.\n", dequeue(&q));
    traversePrint(&q);
    return 0;
}
