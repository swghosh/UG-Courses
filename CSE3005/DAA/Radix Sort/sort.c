//
//  sort.c
//  Radix Sort
//
//  Created by Swarup Ghosh on 14/11/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include "sort.h"

#define K 10

unsigned int *counting_sort(unsigned int *array, size_t size, unsigned int radix) {
    unsigned int *element_counts, *sorted_array, x;
    int iter_index;
    
    element_counts = calloc(K, sizeof(unsigned int)); // count from [0, ..., k)
    
    for(iter_index = 0; iter_index < size; iter_index++) {
        x = (array[iter_index] / radix) % 10;
        element_counts[x]++;
    }
    
    for(iter_index = 1; iter_index < K; iter_index++) {
        element_counts[iter_index] += element_counts[iter_index - 1];
    }
    
    sorted_array = malloc(sizeof(unsigned int) * size);
    x = 0;
    for(iter_index = (int)(size - 1); iter_index >= 0; iter_index--) {
        x = array[iter_index];
        sorted_array[element_counts[(x / radix) % 10] - 1] = x;
        element_counts[(x / radix) % 10] -= 1;
    }
    
    free(element_counts);
    return sorted_array;
}
