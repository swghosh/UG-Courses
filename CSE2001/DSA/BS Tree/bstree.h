//
//  bstree.h
//  BS Tree
//
//  Created by Swarup Ghosh on 07/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

/* Xcode generated define, for inclusion only once */
#ifndef bstree_h
#define bstree_h

#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int dataValue;
    struct treeNode *left, *right;
};
#define NODE struct treeNode

struct bsTree {
    struct treeNode *root;
};
#define TREE struct bsTree

void init(TREE *bst);
void insert(TREE *bst, int data); // internally uses putData() and createNode()
void traverseInOrder(TREE *bst); // interanlly uses traverse()

NODE *createNode(int data);
void putData(NODE *node, int data);
void traverseNode(NODE *node);

#endif /* bstree_h */
