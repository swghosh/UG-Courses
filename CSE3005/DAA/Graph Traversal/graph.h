//
//  graph.h
//  Graph
//
//  Created by Swarup Ghosh on 13/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

/* Xcode generated define, for inclusion only once */
#ifndef graph_h
#define graph_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct graph {
    struct verticesListNode *vertices;
};

struct verticesListNode {
    struct vertice *vertice;
    struct verticesListNode *next;
};

struct vertice {
    int dataValue;
    struct edgesListNode *edges;
    bool _visited;
};

struct edgesListNode {
    struct vertice *point;
    struct edgesListNode *next;
};

#define GRAPH struct graph
#define VERTICE struct vertice
#define VLISTN struct verticesListNode
#define ELISTN struct edgesListNode

void init(GRAPH *graph);
void addNewVertice(GRAPH *graph, VERTICE *vertice);
void addNewEdge(VERTICE *fromVertice, VERTICE *toVertice);

void verticeInfo(VERTICE *vertice);
void traverse(GRAPH *graph, VERTICE *start);

void bfTraverse(VERTICE *start);

VERTICE *createVertice(int data);
VLISTN *createVListNode(VERTICE *vertice);
ELISTN *createEListNode(VERTICE *toVertice);

#define QUEUE_MAX 1000
void enBfQ(VERTICE *vertice);
VERTICE *deBfQ(void);
bool isBfQEmpty(void);

#endif /* graph_h */
