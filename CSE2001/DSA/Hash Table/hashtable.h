//
//  hashtable.h
//  Hash Table
//
//  Created by Swarup Ghosh on 20/12/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#ifndef hashtable_h
#define hashtable_h

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

struct item {
    int key, value;
};
#define ITEM struct item

struct hashTable {
    struct item *items[SIZE];
};
#define TABLE struct hashTable

ITEM *createItem(int key, int value);

void init(TABLE *table);
int hash(int key);
void addToTable(TABLE *table, ITEM *item);
ITEM *getFromTable(TABLE *table, int key);

void traverseTable(TABLE *table);

#endif /* hashtable_h */
