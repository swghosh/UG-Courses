#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
#define NODE struct node

NODE *createNode(int value) {
    NODE *aNode;
    aNode = malloc(sizeof(NODE));
    aNode->value = value;
    aNode->next = NULL;
    return aNode;
}

void display(NODE *start) {
    NODE *iter = start;
    if(iter == NULL) {
        fprintf(stderr, "Empty Linked List.");
    }
    else {
        while(iter != NULL) {
            printf("%d -> ", iter->value);
            iter = iter->next;
        }
    }
}

int main() {
    NODE *a, *b, *c;
    int e1, e2, e3;

    e1 = 1, e2 = 2, e3 = 3;
    a = createNode(e1);
    b = createNode(e2);
    c = createNode(e3);

    a->next = b;
    b->next = c;
    c->next = NULL;

    display(a);
}