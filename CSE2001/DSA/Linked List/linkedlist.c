//
//  linkedlist.c
//  Linked List
//
//  Created by Swarup Ghosh on 10/10/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "linkedlist.h"

NODE *createNode(int newValue) {
    NODE *new = (NODE*) malloc(sizeof(NODE));
    new->value = newValue;
    new->next = NULL;
    return new;
}

void init(LIST *ll) {
    ll->start = ll->end = NULL;
}

int count(LIST *ll) {
    int count = 0;
    NODE *iter = ll->start;
    while (iter != NULL) {
        count++;
        iter = iter->next;
    }
    return count;
}

void traversePrint(LIST *ll) {
    NODE *iter = ll->start;
    if(iter == NULL) {
        printf("Linked list is empty.");
    }
    else {
        while(iter != NULL) {
            printf("%d -> ", iter->value);
            iter = iter->next;
        }
    }
    puts("");
}

void insertBeginning(LIST *ll, int newValue) {
    NODE *new = createNode(newValue);
    if(ll->start == NULL) {
        ll->start = ll->end = new;
    }
    else {
        new->next = ll->start;
        ll->start = new;
    }
}

void insertEnd(LIST *ll, int newValue) {
    NODE *new = createNode(newValue);
    if(ll->start == NULL) {
        ll->start = ll->end = new;
    }
    else {
        ll->end->next = new;
        ll->end = new;
    }
}

int deleteBeginning(LIST *ll) {
    int deletedValue; NODE *toDelete;
    if(ll->start == NULL) {
        fprintf(stderr, "Deletion Error. Underflow.");
        return INT_MIN;
    }
    else {
        toDelete = ll->start;
        deletedValue = toDelete->value;
        ll->start = toDelete->next;
        free(toDelete);
        return deletedValue;
    }
}

int deleteEnd(LIST *ll) {
    NODE *iter; int deleteValue;
    if(ll->end == NULL) {
        fprintf(stderr, "Deletion Error. Underflow.");
        return INT_MIN;
    }
    else if(ll->start->next == NULL) {
        deleteValue = ll->start->value;
        iter = ll->start;
        ll->start = ll->end = NULL;
        free(iter);
        return deleteValue;
    }
    else {
        iter = ll->start;
        while(iter->next->next != NULL) {
            iter = iter->next;
        }
        ll->end = iter;
        deleteValue = iter->next->value;
        free(iter->next);
        iter->next = NULL;
        return deleteValue;
    }
}

int search(LIST *haystack, int needle) {
    NODE *iter = haystack->start;
    int iterIndex = 0;
    while (iter != NULL) {
        if(iter->value == needle) {
            return iterIndex;
        }
        iterIndex++;
        iter = iter->next;
    }
    return -1;
}

void insertMiddle(LIST *ll, int position, int newValue) {
    int iterIndex = 0;
    NODE *iter = ll->start;
    if(position > count(ll)) {
        fprintf(stderr, "Insertion not possible at given position.");
    }
    else {
        while(iterIndex < position - 1) {
            iterIndex++;
            iter = iter->next;
        }
        NODE *temp = iter->next->next;
        NODE *new = createNode(newValue);
        new->next = temp;
        iter->next = new;
        
        if(ll->end->next == new) {
            ll->end = new;
        }
    }
}

int deleteMiddle(LIST *ll, int position) {
    int iterIndex = 0;
    NODE *iter = ll->start;
    if(position > count(ll)) {
        fprintf(stderr, "Deletion not possible at given position.");
        return INT_MIN;
    }
    else {
        while(iterIndex < position - 1) {
            iterIndex++;
            iter = iter->next;
        }
        NODE *toDelete = iter->next;
        
        if(ll->end == toDelete) {
            ll->end = iter;
        }
        
        int deleteValue = toDelete->value;
        free(toDelete);
        iter->next = iter->next->next;
        return deleteValue;
    }
}
