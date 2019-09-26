//
//  main.c
//  Counting Sort
//
//  Created by Swarup Ghosh on 26/09/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

unsigned int *counting_sort(unsigned int *array, unsigned int k, size_t size) {
    unsigned int *element_counts, *sorted_array, iter_index, iter_index2, x;
    
    element_counts = calloc(k + 1, sizeof(unsigned int)); // count from [0, ..., k] (including k)
    
    for(iter_index = 0; iter_index < size; iter_index++) {
        x = array[iter_index];
        element_counts[x]++;
    }
    
    sorted_array = malloc(sizeof(unsigned int) * size);
    x = 0;
    for(iter_index = 0; iter_index < k + 1; iter_index++) {
        for(iter_index2 = 0; iter_index2 < element_counts[iter_index]; iter_index2++) {
            sorted_array[x] = iter_index;
            x++;
        }
    }
    return sorted_array;
}

unsigned int max(unsigned int *array, size_t size) {
    unsigned int iter_index, k;
    k = 0; // the minimum possible value for +ve integers can be 0
    for(iter_index = 0; iter_index < size; iter_index++) {
        if(array[iter_index] > k)
            k = array[iter_index];
    }
    return k;
}

int main() {
    unsigned int *user_elements, *sorted_elements, k, iter_index;
    size_t user_length;
    printf("How many numbers? (integer expected) > ");
    scanf("%ld", &user_length);
    
    // will save memory from internal fragmentation
    user_elements = malloc(sizeof(unsigned int) * user_length);
    
    printf("Specify all numbers. (space seperated, %ld +ve integers expected) > ", user_length);
    for(iter_index = 0; iter_index < user_length; iter_index++) {
        scanf("%d", user_elements + iter_index);
    }
    
    k = max(user_elements, user_length);
    printf("%u\n", k);
    sorted_elements = counting_sort(user_elements, k, user_length);
    
    printf("Displaying numbers after performing sort.\n");
    for(iter_index = 0; iter_index < user_length; iter_index++) {
        printf("%d | ", sorted_elements[iter_index]);
    }
    puts("");
    return 0;
}
