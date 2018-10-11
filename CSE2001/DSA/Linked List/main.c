//
//  main.c
//  Linked List
//
//  Created by Swarup Ghosh on 10/10/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkedlist.h"

int main(int argc, const char * argv[]) {
    LIST list;
    init(&list);
    
    int choice, element, position;
    
    puts("---------------------");
    puts("|No.\t|Choice\t\t|");
    puts("---------------------");
    puts("|1\t\t|Insert F.\t|");
    puts("|2\t\t|Delete F.\t|");
    puts("|3\t\t|Insert R.\t|");
    puts("|4\t\t|Delete R.\t|");
    puts("|5\t\t|Insert M.\t|");
    puts("|6\t\t|Delete M.\t|");
    puts("|7\t\t|Search\t\t|");
    puts("|8\t\t|Count\t\t|");
    puts("|9\t\t|Print\t\t|");
    puts("|10\t\t|Exit\t\t|");
    puts("---------------------");
    
    while(true) {
        printf("Specify choice (integer 1-4, expected) -> ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Specify element to insert (integer expected) ->");
                scanf("%d", &element);
                printf("Inserting element, %d.\n", element);
                insertBeginning(&list, element);
                break;
            case 2:
                element = deleteBeginning(&list);
                printf((element != INT_MIN) ? "Deleting element done (%d).\n" : "Deleting element failed.\n", element);
                break;
            case 3:
                printf("Specify element to insert (integer expected) ->");
                scanf("%d", &element);
                printf("Insert element, %d.\n", element);
                insertEnd(&list, element);
                break;
            case 4:
                element = deleteEnd(&list);
                printf((element != INT_MIN) ? "Deleting element done (%d).\n" : "Deleting element failed.\n", element);
                break;
            case 5:
                printf("Specify element to insert (integer expected) ->");
                scanf("%d", &element);
                printf("Specify position for insertion (integer expected) ->");
                scanf("%d", &position);
                printf("Inserting element, %d.\n", element);
                insertMiddle(&list, position, element);
                break;
            case 6:
                printf("Specify position for deletion (integer expected) ->");
                scanf("%d", &position);
                element = deleteMiddle(&list, position);
                printf((element != INT_MIN) ? "Deleting element done (%d).\n" : "Deleting element failed.\n", element);
                break;
            case 7:
                printf("Specify element to search (integer expected) ->");
                scanf("%d", &element);
                printf("Searching element, %d.\n", element);
                position = search(&list, element);
                printf((position != -1) ? "Element found at position %d.\n" : "Element not found.\n", position + 1);
                break;
            case 8:
                printf("Linked List contains %d element(s).\n", count(&list));
                break;
            case 9:
                puts("Linked List contains: ");
                traversePrint(&list);
                break;
            case 10:
                exit(0);
                break;
                
            default:
                puts("Invalid choice, please retry.");
                break;
        }
    }
    
    return 0;
}

