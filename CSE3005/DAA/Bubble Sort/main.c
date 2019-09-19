//
//  main.c
//  Bubble Sort
//
//  Created by Swarup Ghosh on 30/10/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int *bubble_sort(int *array, int length) {
    int index_a, index_b, temp;
    for(index_a = 0; index_a < length - 1; index_a++) {
        for(index_b = 0; index_b < length - index_a - 1; index_b++) {
            if(array[index_b] > array[index_b + 1]) {
                temp = array[index_b];
                array[index_b] = array[index_b + 1];
                array[index_b + 1] = temp;
            }
        }
    }
    return array;
}

int main() {
    int *user_elements, user_length, iter_index;
    printf("How many numbers? (integer expected) > ");
    scanf("%d", &user_length);
    
    // will save memory from internal fragmentation
    user_elements = (int*) malloc(sizeof(int) * user_length);
    
    printf("Specify all numbers. (space seperated, %d integers expected) > ", user_length);
    for(iter_index = 0; iter_index < user_length; iter_index++) {
        scanf("%d", user_elements + iter_index);
    }
    
    bubble_sort(user_elements, user_length);
    
    printf("Displaying numbers after performing sort.\n");
    for(iter_index = 0; iter_index < user_length; iter_index++) {
        printf("%d | ", user_elements[iter_index]);
    }
    puts("");
    
    return 0;
}
