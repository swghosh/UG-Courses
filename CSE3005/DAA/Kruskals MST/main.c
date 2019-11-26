//
//  main.c
//  Kruskals MST
//
//  Created by Swarup Ghosh on 26/11/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int *msort(int *array, int len);
int kruskal(int **graph, int len_vertices);
int set_find(int *sets, int len, int u);
int set_union(int u, int v);

int main(int argc, const char * argv[]) {
    int **graph, len_vertices;
    printf("Number of vertices? (integer < 32 expected) -> ");
    scanf("%d", &len_vertices);
    
    int iter_a, iter_b;
    graph = (int**) malloc(sizeof(int*) * len_vertices);
    for(iter_a = 0; iter_a < len_vertices; iter_a++) {
        graph[iter_a] = (int*) malloc(sizeof(int) * len_vertices);
    }
    
    printf("Adjacency Matrix for weighted graph edges.\n0 indicates absence of edge.\n");
    printf("(%d integers expected) -> \n", len_vertices * len_vertices);
    for(iter_a = 0; iter_a < len_vertices; iter_a++) {
        for(iter_b = 0; iter_b < len_vertices; iter_b++) {
            scanf("%d", &graph[iter_a][iter_b]);
            if(graph[iter_a][iter_b] == 0) graph[iter_a][iter_b] = INT_MAX; // self loop is not considered an edge
        }
    }
    
    printf("Spanning Tree Edges.\n");
    int cost;
    cost = kruskal(graph, len_vertices);
    printf("Spanning Cost: %d.\n", cost);
    
    return 0;
}

int kruskal(int **graph, int len_vertices) {
    int *edges, *sets;
    
    edges = (int*) malloc(sizeof(int) * len_vertices * len_vertices);
    sets = (int*) malloc(sizeof(int) * len_vertices);
    
    int a, b;
    // represents sets 1000 0000 ... 0000, 0100 0000 ... 0000, so on
    for(a = 0; a < len_vertices; a++) {
        b = pow(2, 31 - a);
        sets[a] = b;
    }
    
    // fill array with edges values
    for(a = 0; a < len_vertices * len_vertices; a++) {
        edges[a] = graph[a / len_vertices][a % len_vertices];
    }
    // sort the edges array
    edges = msort(edges, len_vertices * len_vertices);
    
    long long int A = 0; // set containing MST edges
    int u, v;
    int c, d;
    
    int cost = 0;
    for(a = 0; a < len_vertices * len_vertices; a++) {
        b = edges[a];
        
        u = b / len_vertices;
        v = b % len_vertices;
        
        c = set_find(sets, len_vertices, pow(2, 31 - u));
        d = set_find(sets, len_vertices, pow(2, 31 - v));
        
        if(c != d) {
            if((A & b) != b) {
                A = A | b;
                printf("Find and union edge (%d, %d) to tree (set A) \n", u, v);
                cost += graph[u][v];
            }
            
            sets[c] = set_union(sets[u], sets[v]);
            sets[d] = 0;
        }
    }
    printf("%x\n", A);
    return cost;
}

int *msort(int *array, int len) {
    int *extra_array;
    extra_array = (int*) malloc(sizeof(int) * len);
    
    int a, b, min_pos, temp;
    for(a = 0; a < len; a++) {
        min_pos = a;
        
        for(b = a; b < len; b++) {
            if(array[b] < array[min_pos]) min_pos = b;
        }
        
        temp = array[min_pos];
        array[min_pos] = array[a];
        array[a] = temp;
        
        extra_array[a] = min_pos;
    }
    free(array);
    return extra_array;
}

int set_find(int *sets, int len, int u) {
    int i, x;
    for(i = 0; i < len; i++) {
        x = sets[i] & u;
        if(x == u) {
            return i;
        }
    }
    return -1;
}

int set_union(int u, int v) {
    return u | v;
}
