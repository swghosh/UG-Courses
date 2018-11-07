//
//  main.c
//  BS Tree
//
//  Created by Swarup Ghosh on 07/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>

#include "bstree.h"

int main() {
    TREE myBst;
    init(&myBst);
    for(int index = 0; index < 20; index++) {
        insert(&myBst, rand() % 500);
    }
    traverseInOrder(&myBst);
    printf("\n");
}
