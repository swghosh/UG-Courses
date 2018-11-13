//
//  graph.c
//  Graph
//
//  Created by Swarup Ghosh on 13/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "graph.h"
#include <string.h>

void init(GRAPH *graph) {
    graph->vertices = NULL;
}

VERTICE *createVertice(int data) {
    VERTICE *new;
    new = (VERTICE*) malloc(sizeof(VERTICE));
    new->dataValue = data;
    // vertice with no edges
    new->edges = NULL;
    return new;
}

VLISTN *createVListNode(VERTICE *vertice) {
    VLISTN *new;
    new = (VLISTN*) malloc(sizeof(VLISTN));
    new->vertice = vertice;
    new->next = NULL;
    return new;
}

ELISTN *createEListNode(VERTICE *toVertice) {
    ELISTN *new;
    new = (ELISTN*) malloc(sizeof(ELISTN));
    new->point = toVertice;
    new->next = NULL;
    return new;
}

void addNewVertice(GRAPH *graph, VERTICE *vertice) {
    VLISTN *temp;
    // zero vertices present in graph
    if(graph->vertices == NULL) {
        graph->vertices = createVListNode(vertice);
    }
    // non-zero number of vertices
    else {
        temp = createVListNode(vertice);
        temp->next = graph->vertices;
        graph->vertices = temp;
    }
}

void addNewEdge(VERTICE *fromVertice, VERTICE *toVertice) {
    ELISTN *temp;
    // vertice has zero edges
    if(fromVertice->edges == NULL) {
        fromVertice->edges = createEListNode(toVertice);
    }
    // non-zero number of edges
    else {
        temp = createEListNode(toVertice);
        temp->next = fromVertice->edges;
        fromVertice->edges = temp;
    }
}

void verticeInfo(VERTICE *vertice) {
    if(vertice == NULL) {
        printf("No such vertice.\n");
        return;
    }
    // vertice data
    printf(":Vertice %d:\n", vertice->dataValue);
    // iterate edges
    ELISTN *iter = vertice->edges;
    printf("Edges\n");
    if(iter == NULL) {
        printf("No edges.\n");
    }
    else {
        while(iter != NULL) {
            printf("%d -> %d;\n", vertice->dataValue, iter->point->dataValue);
            iter = iter->next;
        }
    }
    printf("\n");
}
