//
//  main.c
//  Merge Sort
//
//  Created by Swarup Ghosh on 19/09/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int start, int mid, int end);
void merge_sort(int *array, int start, int end);

void merge(int *array, int start, int mid, int end) {
    int *extra_array;
    int index_a, index_b, index_c;
    
    extra_array = malloc(sizeof(int) * (end - start + 1));
    index_a = start; index_b = mid + 1; index_c = 0;
    
    while(index_a <= mid && index_b <= end) {
        if(array[index_a] <= array[index_b]) {
            extra_array[index_c] = array[index_a];
            index_c++; index_a++;
        }
        else {
            extra_array[index_c] = array[index_b];
            index_c++; index_b++;
        }
    }
    
    // add left side elements
    while(index_a <= mid) {
        extra_array[index_c] = array[index_a];
        index_c++; index_a++;
    }
    
    // add right side elements
    while(index_b <= end) {
        extra_array[index_c] = array[index_b];
        index_c++; index_b++;
    }
    
    for(index_a = start; index_a <= end; index_a++) {
        array[index_a] = extra_array[index_a - start];
    }
}

void merge_sort(int *array, int start, int end) {
    int mid = (start + end) / 2;
    if(start < end) {
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
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
    
    merge_sort(user_elements, 0, user_length - 1);
    
    printf("Displaying numbers after performing sort.\n");
    for(iter_index = 0; iter_index < user_length; iter_index++) {
        printf("%d | ", user_elements[iter_index]);
    }
    puts("");
    
    return 0;
}
