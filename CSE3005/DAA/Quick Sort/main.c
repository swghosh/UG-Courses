//
//  main.c
//  Quick Sort
//
//  Created by Swarup Ghosh on 19/09/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int *elem1, int *elem2);
int partition(int *array, int start, int end);
void quick_sort(int *array, int start, int end);

void quick_sort(int *array, int start, int end) {
    if(!(start < end)) return;
    
    int pivot_index = partition(array, start, end);
    quick_sort(array, start, pivot_index - 1);
    quick_sort(array, pivot_index + 1, end);
}

int partition(int *array, int start, int end) {
    int pivot, index_a, index_b;
    pivot = array[end];
    
    index_a = start;
    for(index_b = start; index_b <= end - 1; index_b++) {
        if(array[index_b] <= pivot) {
            swap(array + index_a, array + index_b);
            index_a++;
        }
    }
    swap(array + index_a, array + end);
    return index_a;
}

void swap(int *elem1, int *elem2) {
    int temp;
    temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
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
    
    quick_sort(user_elements, 0, user_length - 1);
    
    printf("Displaying numbers after performing sort.\n");
    for(iter_index = 0; iter_index < user_length; iter_index++) {
        printf("%d | ", user_elements[iter_index]);
    }
    puts("");
    
    return 0;
}
