//
//  main.c
//  BS Tree
//
//  Created by Swarup Ghosh on 07/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bstree.h"

#define LIMIT 500
#define COUNT 10

int main() {
    TREE aBst;
    init(&aBst);
    
    int choice, element;
    
    puts("-----------------------------");
    printf("| %2s | %20s |\n", "No", "Choice");
    puts("-----------------------------");
    printf("| %2d | %20s |\n", 1, "Insert");
    printf("| %2d | %20s |\n", 2, "Inorder Traversal");
    printf("| %2d | %20s |\n", 3, "Preorder Traversal");
    printf("| %2d | %20s |\n", 4, "Postorder Traversal");
    printf("| %2d | %20s |\n", 5, "Exit");
    puts("-----------------------------");
    
    while(true) {
        printf("Specify choice (integer 1-5, expected) -> ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Specify element to insert (integer expected) ->");
                scanf("%d", &element);
                printf("Inserting element %d.\n", element);
                insert(&aBst, element);
                break;
            case 2:
                printf("Traversing tree in-order.\n");
                traverse(&aBst, inOrder);
                printf("\n");
                break;
            case 3:
                printf("Traversing tree pre-order.\n");
                traverse(&aBst, preOrder);
                printf("\n");
                break;
            case 4:
                printf("Traversing tree post-order.\n");
                traverse(&aBst, postOrder);
                printf("\n");
                break;
            case 5:
                exit(0);
                break;
            default:
                break;
        }
    }
}
