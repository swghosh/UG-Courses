//
//  linkedlist.h
//  Linked List
//
//  Created by Swarup Ghosh on 10/10/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#ifndef linkedlist_h
/* Xcode generated define, for inclusion only once */
#define linkedlist_h

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int value;
    struct node *next;
};
#define NODE struct node

struct linkedList {
    struct node *start;
    struct node *end;
};
#define LINKEDLIST struct linkedList
#define LIST struct linkedList

NODE *createNode(int value);

void init(LIST *ll);
void insertBeginning(LIST *ll, int newValue);
void insertMiddle(LIST *ll, int position, int newValue);
void insertEnd(LIST *ll, int newValue);
int deleteBeginning(LIST *ll);
int deleteMiddle(LIST *ll, int position);
int deleteEnd(LIST *ll);
int count(LIST *ll);
int search(LIST *haystack, int needle);
void traversePrint(LIST *ll);

#endif /* linkedlist_h */
