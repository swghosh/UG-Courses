//
//  main.c
//  Graph
//
//  Created by Swarup Ghosh on 13/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>

#include "graph.h"

// this method will try to create
// a graph of 4 vertices.
// Vertice 100 with edges (200, 300, 400)
// Vertice 200 with edges (300, 400)
// Vertice 300 with edges (400)
// Vertice 400 with no edges

void graphTest1() {
    GRAPH aGraphG;
    VERTICE *vert1, *vert2, *vert3, *vert4;
    
    init(&aGraphG);
    
    vert1 = createVertice(100);
    vert2 = createVertice(200);
    vert3 = createVertice(300);
    vert4 = createVertice(400);
    
    addNewVertice(&aGraphG, vert1);
    addNewVertice(&aGraphG, vert2);
    addNewVertice(&aGraphG, vert3);
    addNewVertice(&aGraphG, vert4);
    
    addNewEdge(vert1, vert2);
    addNewEdge(vert1, vert3);
    addNewEdge(vert1, vert4);
    
    addNewEdge(vert2, vert3);
    addNewEdge(vert2, vert4);
    
    addNewEdge(vert3, vert4);
    
    verticeInfo(vert1);
    verticeInfo(vert2);
    verticeInfo(vert3);
    verticeInfo(vert4);
}

// this method will try to create
// a graph of 5 vertices.
// Vertice 1 with edges (2, 3, 4)
// Vertice 2 with no edges
// Vertice 3 with edges (5)
// Vertice 4 with edges (1, 3, 5)
// Vertice 5 with no edges
void graphTest2() {
    GRAPH anotherGraphH;
    VERTICE *vert1, *vert2, *vert3, *vert4, *vert5;
    
    init(&anotherGraphH);
    
    vert1 = createVertice(1);
    vert2 = createVertice(2);
    vert3 = createVertice(3);
    vert4 = createVertice(4);
    vert5 = createVertice(5);
    
    addNewVertice(&anotherGraphH, vert1);
    addNewVertice(&anotherGraphH, vert2);
    addNewVertice(&anotherGraphH, vert3);
    addNewVertice(&anotherGraphH, vert4);
    addNewVertice(&anotherGraphH, vert5);
    
    addNewEdge(vert1, vert2);
    addNewEdge(vert1, vert3);
    addNewEdge(vert1, vert4);
    
    addNewEdge(vert3, vert5);
    
    addNewEdge(vert4, vert1);
    addNewEdge(vert4, vert3);
    addNewEdge(vert4, vert5);
    
    verticeInfo(vert1);
    verticeInfo(vert2);
    verticeInfo(vert3);
    verticeInfo(vert4);
    verticeInfo(vert5);
    
    printf("BFS Traversal of graph\n");
    traverse(&anotherGraphH, vert4);
}

int main() {
    printf("FIRST TEST GRAPH\n----------------\n");
    graphTest1();
    printf("\nSECOND TEST GRAPH\n-----------------\n");
    graphTest2();
    return 0;
}
