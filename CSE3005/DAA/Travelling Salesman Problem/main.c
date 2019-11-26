//
//  main.c
//  Travelling Salesman Problem
//
//  Created by Swarup Ghosh on 21/11/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

struct ts {
    int min_cost, *tour;
};
#define TS struct ts

TS tsp(int **m, int N, int S);
void setup(int **m, int **memo, int S, int N);
void solve(int **m, int **memo, int S, int N);

struct combo {
    int *comb, len;
};
#define COMBO struct combo

COMBO *combinations(int r, int N);
bool not_in(int i, int subset);

int find_min_cost(int **m, int **memo, int S, int N);
int *find_optimal_tour(int **m, int **memo, int S, int N);

void combi(int set, int at, int r, int n, int *tracker, int *subsets);
int fact(int x);

int main() {
    // m is Graph Adjacency Matrix
    // N is number of Graph Vertices
    int **m, N;
    printf("Number of vertices? (integer expected) -> ");
    scanf("%d", &N);
    
    int a, b;
    m = malloc(sizeof(int*) * N);
    for(a = 0; a < N; a++) {
        m[a] = malloc(sizeof(int) * N);
    }
    
    printf("Adjacency Matrix for weighted graph edges.\n0 indicates absence of edge.\n");
    printf("(%d integers expected) -> \n", N * N);
    for(a = 0; a < N; a++) {
        for(b = 0; b < N; b++) {
            scanf("%d", &m[a][b]);
            if(m[a][b] == 0) m[a][b] = INT_MAX;
        }
    }
    
    int S;
    printf("Starting vertex? (integer < %d expected) -> ", N);
    scanf("%d", &S);
    
    TS ts;
    ts = tsp(m, N, S);
    
    printf("Minimum Cost: %d.\n", ts.min_cost);
    printf("Visited cities. \n");
    for(a = 0; a < N + 1; a++) {
        printf("%d -> ", ts.tour[a]);
    }
    puts("");
    return 0;
}

TS tsp(int **m, int N, int S) {
    int **memo = (int**) malloc(sizeof(int*) * N);
    int i, j;
    for(i = 0; i < N; i++) {
        memo[i] = (int*) malloc(sizeof(int) * (int)pow(2, N));
    }
    
    // fill memo with +inf
    for(i = 0; i < N; i++) {
        for(j = 0; j < (int)pow(2, N); j++) {
            memo[i][j] = INT_MAX;
        }
    }
    
    setup(m, memo, S, N);
    solve(m, memo, S, N);
    
    TS ts;
    ts.min_cost = find_min_cost(m, memo, S, N);
    ts.tour = find_optimal_tour(m, memo, S, N);
    
    return ts;
}

void setup(int **m, int **memo, int S, int N) {
    int i;
    
    
    for(i = 0; i < N; i++) {
        if(i == S) continue;
        memo[i][1 << S | 1 << i] = m[S][i];
    }
}

void solve(int **m, int **memo, int S, int N) {
    int r;
    int i, next, e, min_dist, new_dist;
    int subset, state;
    COMBO *combo;
    for(r = 3; r <= N; r++) {
        combo = combinations(r, N);
        for(i = 0; i < combo->len; i++) {
            subset = combo->comb[i];
            
            if(not_in(S, subset)) continue;
            for(next = 0; next < N; next++) {
                if(next == S || not_in(next, subset)) continue;
                state = subset ^ (1 << next);
                min_dist = INT_MAX;
                
                for(e = 0; e < N; e++) {
                    if(e == S || e == next || not_in(e, subset)) continue;
                    new_dist = memo[e][state] + m[e][next];
                    
                    if(new_dist < min_dist) min_dist = new_dist;
                    memo[next][subset] = min_dist;
                }
            }
        }
    }
}

int fact(int x) {
    if (x <= 1) return 1;
    else return (x * fact(x-1));
}

void combi(int set, int at, int r, int n, int *tracker, int *subsets) {
    if(r == 0) {
        subsets[*tracker] = set;
        (*tracker)++;
    }
    else {
        int i;
        for(i = at; i < n; i++) {
            set = set | (1 << i);
            combi(set, i + 1, r - 1, n, tracker, subsets);
            set = set & ~(1 << i);
        }
    }
}

COMBO *combinations(int r, int N) {
    COMBO *x = malloc(sizeof(COMBO));
    x->len = fact(N) / (fact(r) * fact(N - r));
    x->comb = malloc(sizeof(int) * x->len);
    
    int tracker = 0;
    combi(0, 0, r, N, &tracker, x->comb);
    return x;
}

bool not_in(int i, int subset) {
    return ((1 << i) & subset) == 0;
}

int find_min_cost(int **m, int **memo, int S, int N) {
    int end_state = (1 << N) - 1;
    int min_cost = INT_MAX;
    
    int e, tour_cost;
    for(e = 0; e < N; e++) {
        if(e == S) continue;
        tour_cost = memo[e][end_state] + m[e][S];
        
        if(tour_cost < min_cost) min_cost = tour_cost;
    }
    return min_cost;
}
int *find_optimal_tour(int **m, int **memo, int S, int N) {
    int last_index = S;
    int state = (1 << N) - 1;
    int *tour = malloc(sizeof(int) * (N + 1));
    
    int index, i, j;
    int prev_dist, new_dist;
    for(i = N - 1; i >= 1; i--) {
        index = -1;
        for(j = 0; j < N; j++) {
            if(j == S || not_in(j, state)) continue;
            if(index == -1) index = j;
            
            prev_dist = memo[index][state] + m[index][last_index];
            new_dist = memo[j][state] + m[j][last_index];
            
            if(new_dist < prev_dist) index = j;
        }
        tour[i] = index;
        state = state ^ (1 << index);
        last_index = index;
    }
    
    tour[0] = tour[N] = S;
    return tour;
}

