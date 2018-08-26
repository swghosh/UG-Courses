//
//  main.c
//  Linear Search
//
//  Created by Swarup Ghosh on 26/08/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>

// linear search algorithm to search
// `needle` element from the given
// `haystack` array, returns index
// of searched element, -1 otherwise

int linearSearch(int *haystack, int size, int needle) {
    int iterIndex, *elementPointer = haystack;
    for(iterIndex = 0; iterIndex < size; iterIndex++, elementPointer++) {
        if(*elementPointer == needle) return iterIndex;
    }
    return -1;
}

#define MAX_ELEMENTS 100

int main(void) {
    int numbers[MAX_ELEMENTS], userLength, iterIndex, searchElement, searchedIndex;
    
    printf("How many numbers? (integer < %d, expected) > ", MAX_ELEMENTS);
    scanf("%d", &userLength);
    
    printf("Specify all numbers. (space seperated, %d integers expected) > ", userLength);
    for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
        scanf("%d", &numbers[iterIndex]);
    }
    
    printf("Which element to search for? (integer expected) > ");
    scanf("%d", &searchElement);
    
    searchedIndex = linearSearch(numbers, userLength, searchElement);
    
    printf(((searchedIndex != -1) ? "Search completed. Element found at %d.\n" : "Search completed. Element not found.\n"), searchedIndex + 1);
    
    return 0;
}
