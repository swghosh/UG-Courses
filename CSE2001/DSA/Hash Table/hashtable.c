//
//  hashtable.c
//  Hash Table
//
//  Created by Swarup Ghosh on 20/12/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "hashtable.h"

void init(TABLE *table) {
    int iterIndex;
    for(iterIndex = 0; iterIndex < SIZE; iterIndex++) table->items[iterIndex] = NULL;
}

ITEM *createItem(int key, int value) {
    ITEM *new = (ITEM*) malloc(sizeof(ITEM));
    new->key = key;
    new->value = value;
    return new;
}

int hash(int key) {
    return key % SIZE;
}

void addToTable(TABLE *table, ITEM *item) {
    int hashIndex = hash(item->key);
    while(table->items[hashIndex] != NULL) {
        hashIndex++;
        hashIndex = hash(hashIndex);
    }
    table->items[hashIndex] = item;
}

ITEM *getFromTable(TABLE *table, int key) {
    int hashIndex = hash(key);
    while(table->items[hashIndex] != NULL) {
        if(table->items[hashIndex]->key == key) break;
        hashIndex++;
        hashIndex = hash(hashIndex);
    }
    return table->items[hashIndex];
}

void traverseTable(TABLE *table) {
    int iterIndex;
    puts("All key value pairs.");
    for(iterIndex = 0; iterIndex < SIZE; iterIndex++) {
        if(table->items[iterIndex] == NULL) printf("(~, ~) - ");
        else printf("(%d, %d) - ", table->items[iterIndex]->key, table->items[iterIndex]->value);
    }
}
