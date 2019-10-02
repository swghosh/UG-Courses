//
//  main.c
//  Heap Sort
//
//  Created by Swarup Ghosh on 26/09/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *array, int size, int pos) {
    int largest, left, right;
    // largest is current position initially
    largest = pos;
    left = 2 * pos + 1;
    right = left + 1;
    
    // left child larger than root
    if(left < size && array[left] > array[largest]) largest = left;
    // right child larger than root
    if(right < size && array[right] > array[largest]) largest = right;
    
    // largest is not root
    if(largest != pos) {
        // perform swap
        swap(&array[pos], &array[largest]);
        heapify(array, size, largest);
    }
}

void heap_sort(int *array, int size) {
    int index;
    // rearrange array
    for(index = size / 2 - 1; index >= 0; index--)
        heapify(array, size, index);
    // one by one element from heap
    for(index = size - 1; index >= 0; index--) {
        // swap root with end position
        swap(&array[0], &array[index]);
        // max heapify again
        heapify(array, index, 0);
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
    
    heap_sort(user_elements, user_length);
    
    printf("Displaying numbers after performing sort.\n");
    for(iter_index = 0; iter_index < user_length; iter_index++) {
        printf("%d | ", user_elements[iter_index]);
    }
    puts("");
    
    return 0;
}
