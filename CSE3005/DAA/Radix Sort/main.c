//
//  main.c
//  Radix Sort
//
//  Created by Swarup Ghosh on 14/11/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sort.h"

#define DIGITS 4

unsigned int *radix_sort(unsigned int *array, size_t size) {
    int iter;
    unsigned int radix;
    for(iter = 0; iter < DIGITS; iter++) {
        radix = (unsigned int)pow(10, iter);
        array = counting_sort(array, size, radix);
    }
    return array;
}

int main() {
    unsigned int *user_elements, *sorted_elements, iter_index;
    size_t user_length;
    printf("How many numbers? (integer expected) > ");
    scanf("%ld", &user_length);
    
    // will save memory from internal fragmentation
    user_elements = malloc(sizeof(unsigned int) * user_length);
    
    printf("Specify all numbers. (space seperated, %ld +ve integers < 10000 expected) > ", user_length);
    for(iter_index = 0; iter_index < user_length; iter_index++) {
        scanf("%d", user_elements + iter_index);
    }
    
    sorted_elements = radix_sort(user_elements, user_length);
    
    printf("Displaying numbers after performing sort.\n");
    for(iter_index = 0; iter_index < user_length; iter_index++) {
        printf("%d | ", sorted_elements[iter_index]);
    }
    puts("");
    return 0;
}
