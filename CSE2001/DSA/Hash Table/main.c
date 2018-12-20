//
//  main.c
//  Hash Table
//
//  Created by Swarup Ghosh on 20/12/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>

#include "hashtable.h"

int main(int argc, const char * argv[]) {
    TABLE myHashTable;
    init(&myHashTable);
    
    ITEM *i1, *i2, *i3, *i4, *i5, *i6, *i7;
    i1 = createItem(10001, 21);
    i2 = createItem(90, 91);
    i3 = createItem(2012, 51);
    i4 = createItem(89, 90);
    i5 = createItem(678, 781);
    i6 = createItem(111, 234);
    i7 = createItem(338, 12391);
    
    addToTable(&myHashTable, i1);
    addToTable(&myHashTable, i2);
    addToTable(&myHashTable, i3);
    addToTable(&myHashTable, i4);
    addToTable(&myHashTable, i5);
    addToTable(&myHashTable, i6);
    addToTable(&myHashTable, i7);
    
    traverseTable(&myHashTable);
    
    return 0;
}
