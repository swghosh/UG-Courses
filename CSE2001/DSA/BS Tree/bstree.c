//
//  bstree.c
//  BS Tree
//
//  Created by Swarup Ghosh on 07/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "bstree.h"

// initialise the binary search
// tree, set root node null initially
void init(TREE *bst) {
    bst->root = NULL;
}

// creates a new tree node
// with left and right as null
NODE *createNode(int data) {
    NODE *new;
    new = (NODE*) malloc(sizeof(NODE));
    new->left = NULL;
    new->right = NULL;
    new->dataValue = data;
    return new;
}

// recursively puts the data entry
// in the subsequent node based
// on BST condition
void putData(NODE *node, int data) {
    if(data > node->dataValue) {
        if(node->right == NULL) {
            node->right = createNode(data);
        }
        else {
            putData(node->right, data);
        }
    }
    else {
        if(node->left == NULL) {
            node->left = createNode(data);
        }
        else {
            putData(node->left, data);
        }
    }
}

// inserts a new element into
// the tree based on the bs tree
void insert(TREE *bst, int data) {
    if(bst->root == NULL) {
        bst->root = createNode(data);
    }
    else {
        putData(bst->root, data);
    }
}

// traverse each node of the
// tree recursively based on
// provided order
void traverseNode(NODE *node, ORDER order) {
    switch(order) {
        case inOrder:
            // in order is left root right
            // first, left
            if(node->left != NULL) {
                traverseNode(node->left, order);
            }
            // then, root
            printf("%d -- ", node->dataValue);
            // then, right
            if(node->right != NULL) {
                traverseNode(node->right, order);
            }
            break;
        case preOrder:
            // pre order is root left right
            printf("%d -- ", node->dataValue);
            if(node->left != NULL) {
                traverseNode(node->left, order);
            }
            if(node->right != NULL) {
                traverseNode(node->right, order);
            }
            break;
        case postOrder:
            // post order is left right root
            if(node->left != NULL) {
                traverseNode(node->left, order);
            }
            if(node->right != NULL) {
                traverseNode(node->right, order);
            }
            printf("%d -- ", node->dataValue);
            break;
    }
}

// traverses a given tree
// using the in order technique
void traverse(TREE *bst, ORDER order) {
    if(bst->root == NULL) {
        fprintf(stderr, "Empty Binary Search Tree.");
    }
    else {
        traverseNode(bst->root, order);
    }
}
