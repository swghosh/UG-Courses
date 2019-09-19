//
//  main.c
//  Selection Sort
//
//  Created by Swarup Ghosh on 22/08/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int *selection_sort(int *array, int length) {
    int index_a, index_b, temp, min_pos;
    for(index_a = 0; index_a < length - 1; index_a++) {
        min_pos = index_a;
        for(index_b = index_a; index_b < length; index_b++) {
            if(array[index_b] < array[min_pos])
                min_pos = index_b;
        }
        temp = array[min_pos];
        array[min_pos] = array[index_a];
        array[index_a] = temp;
    }
    return array;
}

int main() {
    int *user_array, count, iter_index;
    printf("How many numbers? (integer expected) > ");
    scanf("%d", &count);
    
    // will save memory from internal fragmentation
    user_array = (int*) malloc(sizeof(int) * count);
    
    printf("Specify all numbers. (space seperated, %d integers expected) > ", count);
    for(iter_index = 0; iter_index < count; iter_index++) {
        scanf("%d", user_array + iter_index);
    }
    
    selection_sort(user_array, count);
    
    printf("Displaying numbers after performing sort.\n");
    for(iter_index = 0; iter_index < count; iter_index++) {
        printf("%d | ", user_array[iter_index]);
    }
    puts("");
    
    return 0;
}
