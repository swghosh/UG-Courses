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
    enqueue(&q, 20, 10);
    enqueue(&q, 30, 6);
    enqueue(&q, 30, 20);
    printf("HIGHEST PRIORITY :%d, priority = %d:\n", q.highestPriority->data, q.highestPriority->priority);
    traversePrint(&q);
    return 0;
}
