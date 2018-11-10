//
//  main.c
//  BS Tree
//
//  Created by Swarup Ghosh on 07/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>

#include "bstree.h"

#define LIMIT 500
#define COUNT 10

int main() {
    TREE aBst;
    init(&aBst);
    
    for(int index = 0; index < COUNT; index++) {
        insert(&aBst, rand() % LIMIT);
    }
    
    puts("In Order Traversal");
    traverse(&aBst, inOrder);
    printf("\n\n");
    puts("Pre Order Traversal");
    traverse(&aBst, preOrder);
    printf("\n\n");
    puts("Post Order Traversal");
    traverse(&aBst, postOrder);
    printf("\n\n");
}
