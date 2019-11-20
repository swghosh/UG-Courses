//
//  main.c
//  Knapsack Problem
//
//  Created by Swarup Ghosh on 21/11/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void sort(float *array, int *array1, int *array2, int length);

int main() {
    int *weights, *costs;
    float *v;
    int n, capacity;
    
    printf("Knapsack capacity (integer exepected) -> ");
    scanf("%d", &capacity);
    
    printf("Available number of weights (integer exepected) -> ");
    scanf("%d", &n);
    
    weights = malloc(sizeof(int) * n);
    costs = malloc(sizeof(int) * n);
    v = malloc(sizeof(float) * n);
    
    int iter;
    
    printf("Weights (%d integers expected) -> ", n);
    for(iter = 0; iter < n; iter++) {
        scanf("%d", &weights[iter]);
    }
    
    printf("Costs (%d integers expected) -> ", n);
    for(iter = 0; iter < n; iter++) {
        scanf("%d", &costs[iter]);
        
        // assign v(i) = cost(i) / weight(i)
        v[iter] = (float)costs[iter] / (float)weights[iter];
    }
    
    // sort according to descending order of v
    sort(v, weights, costs, n);
    
    int *x, weight = 0, profit = 0;
    x = calloc(n, sizeof(int)); iter = 1;
    while(iter <= n && weight < capacity) {
        if(weight + weights[iter] <= capacity) {
            x[iter] = 1;
        }
        else {
            x[iter] = (capacity - weight) / weights[iter];
        }
        profit += costs[iter] * x[iter];
        weight = weight + (x[iter] * weights[iter]);
        iter++;
    }
    
    puts("");
    for(iter = 0; iter < n; iter++) {
        printf("Cost (%d) x Weight (%d) | ", costs[iter], x[iter]);
    }
    puts("\n");
    printf("Profit: %d\n", profit);
    
    return 0;
}

// sorting in descending order of primary array
void sort(float *array, int *array1, int *array2, int length) {
    int index_a, index_b, temp;
    for(index_a = 1; index_a < length; index_a++) {
        for(index_b = index_a; index_b > 0 && array[index_b - 1] < array[index_b]; index_b--) {
            // sort the v array
            temp = array[index_b];
            array[index_b] = array[index_b - 1];
            array[index_b - 1] = temp;
            
            // accordingly sort the weights array
            temp = array1[index_b];
            array1[index_b] = array1[index_b - 1];
            array1[index_b - 1] = temp;
            
            // accordingly sort the costs array
            temp = array2[index_b];
            array2[index_b] = array2[index_b - 1];
            array2[index_b - 1] = temp;
        }
    }
}
