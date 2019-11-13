//
//  main.c
//  Minimum Spanning Tree
//
//  Created by Swarup Ghosh on 07/11/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "charset.h"

int prims(int **graph, int len_vertices, int start_vertex) {
    CHARSET v, s;
    init(&v); init(&s);

    CHARSET *v_s;

    // insert all vertices to set
    int iter = 0;
    for(iter = 0; iter < len_vertices; iter++) {
        insert(&v, iter);
    }

    // insert the starting vertex to set
    insert(&s, start_vertex);

    CHARSET tree;
    init(&tree);

    int iter1, iter2;
    int min, tracker;
    int from, to;
    
    int ctr = 0;
    int cost = 0;
    while(true) {
        v_s = difference(&v, &s);
        min = INT_MAX;
        for(iter1 = 0; iter1 < len_vertices; iter1++) {
            from = element(&s, iter1);
            if(from == -1) break;
            for(iter2 = 0; iter2 < len_vertices; iter2++) {
                to = element(v_s, iter2);
                if(to == -1) break;
                if(graph[from][to] < min) {
                    min = graph[from][to];
                    tracker = from * len_vertices + to;
                }
            }
        }
        insert(&s, tracker % len_vertices);
        insert(&tree, tracker);
        free(v_s);
        if(min == INT_MAX) break;
        
        cost += min;
        ctr++;
    }
    
    
    printf("Minimum Spanning Tree.\n");
    for(iter = 0; iter < len_vertices - 1; iter++) {
        tracker = element(&tree, iter);
        if(tracker == -1) break;
        printf("(%d, %d) ", tracker / len_vertices, tracker % len_vertices);
    }
    printf("\n");
    
    return cost;
}

int main() {
    int **graph, len_vertices;
    printf("Number of vertices? (integer expected) -> ");
    scanf("%d", &len_vertices);
    
    int iter_a, iter_b;
    graph = malloc(sizeof(int*) * len_vertices);
    for(iter_a = 0; iter_a < len_vertices; iter_a++) {
        graph[iter_a] = malloc(sizeof(int) * len_vertices);
    }
    
    printf("Adjacency Matrix for weighted graph edges.\n0 indicates absence of edge.\n");
    printf("(%d integers expected) -> \n", len_vertices * len_vertices);
    for(iter_a = 0; iter_a < len_vertices; iter_a++) {
        for(iter_b = 0; iter_b < len_vertices; iter_b++) {
            scanf("%d", &graph[iter_a][iter_b]);
            if(graph[iter_a][iter_b] == 0) graph[iter_a][iter_b] = INT_MAX;
        }
    }
    
    int cost;
    cost = prims(graph, len_vertices, 0);
    printf("Spanning cost: %d\n", cost);
    
    return 0;
}
