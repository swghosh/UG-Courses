//
//  graph.c
//  Graph
//
//  Created by Swarup Ghosh on 13/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include "graph.h"

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

VERTICE *bfQueue[QUEUE_MAX];
int bfQFront = -1, bfQRear = -1;
void enBfQ(VERTICE *vertice) {
    if(bfQRear + 1 == QUEUE_MAX) {
        fprintf(stderr, "Queue Overflow.\n");
    }
    else {
        if(bfQFront == -1 && bfQRear == -1) bfQFront = bfQRear = 0;
        else bfQRear++;
        bfQueue[bfQRear] = vertice;
    }
}
VERTICE *deBfQ() {
    VERTICE *del;
    if(bfQRear == -1 && bfQFront == -1) {
        fprintf(stderr, "Queue Underflow.\n");
        return NULL;
    }
    else {
        del = bfQueue[bfQFront];
        if(bfQFront == bfQRear) bfQFront = bfQRear = -1;
        else bfQFront = bfQFront + 1;
    }
    return del;
}
bool isBfQEmpty() {
    return (bfQFront == -1) && (bfQRear == -1);
}

void traverse(GRAPH *graph, VERTICE *start) {
    // set all vertices to univisited
    VLISTN *iter = graph->vertices;
    // empty graph,
    // premature termination
    if(iter == NULL) return;
    while(iter != NULL) {
        iter->vertice->_visited = false;
        iter = iter->next;
    }
    
    bfQFront = bfQRear = -1;
    bfTraverse(start);
}

void bfTraverse(VERTICE *vertice) {
    VERTICE *vTemp; ELISTN *eTemp;
    enBfQ(vertice);
    vertice->_visited = true;
    
    // traverse across adjacency list
    // with a queue
    while(!isBfQEmpty()) {
        vTemp = deBfQ();
        printf(":Vertice %d:\n", vTemp->dataValue);
        eTemp = vTemp->edges;
        while(eTemp != NULL) {
            if(!(eTemp->point->_visited)) {
                enBfQ(eTemp->point);
                eTemp->point->_visited = true;
            }
            eTemp = eTemp->next;
        }
    }
}

