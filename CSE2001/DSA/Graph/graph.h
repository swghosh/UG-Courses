//
//  graph.h
//  Graph
//
//  Created by Swarup Ghosh on 13/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <stdio.h>
#include <stdlib.h>

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

VERTICE *createVertice(int data);
VLISTN *createVListNode(VERTICE *vertice);
ELISTN *createEListNode(VERTICE *toVertice);

#endif /* graph_h */
