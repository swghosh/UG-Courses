//
//  main.c
//  Insertion Sort
//
//  Created by Swarup Ghosh on 22/08/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *array, int length) {
    int index_a, index_b, temp;
    for(index_a = 1; index_a < length; index_a++) {
        for(index_b = index_a; index_b > 0 && array[index_b - 1] > array[index_b]; index_b--) {
            temp = array[index_b];
            array[index_b] = array[index_b - 1];
            array[index_b - 1] = temp;
        }
    }
}

int main() {
    int *elements, user_size, iter_index;
    printf("How many numbers? (integer expected) > ");
    scanf("%d", &user_size);
    
    // will save memory from internal fragmentation
    elements = (int*) malloc(sizeof(int) * user_size);
    
    printf("Specify all numbers. (space seperated, %d integers expected) > ", user_size);
    for(iter_index = 0; iter_index < user_size; iter_index++) {
        scanf("%d", elements + iter_index);
    }
    
    insertion_sort(elements, user_size);
    
    printf("Displaying numbers after performing sort.\n");
    for(iter_index = 0; iter_index < user_size; iter_index++) {
        printf("%d | ", elements[iter_index]);
    }
    
    puts("");
    
    return 0;
}
