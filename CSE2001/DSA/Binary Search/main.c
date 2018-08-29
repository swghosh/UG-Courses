//
//  binarysearch.c
//  Binary Search
//
//  Created by Swarup Ghosh on 26/08/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>

int binarySearch(int* haystack, int needle, int lowerBound, int upperBound);
// binary search algorithm to search
// `needle` element from the given
// `haystack` array with specified limits,
// returns index of searched
// element, -1 otherwise
// (internal usage of recursion)

int binarySearch(int *haystack, int needle, int lowerBound, int upperBound) {
    int meanBound = (lowerBound + upperBound) / 2;
    
    if(*(haystack + meanBound) == needle)
       return meanBound;
    else if(lowerBound == upperBound)
        return -1;
    else if(needle > *(haystack + meanBound))
        return binarySearch(haystack, needle, meanBound + 1, upperBound);
    else if(needle < *(haystack + meanBound))
        return binarySearch(haystack, needle, lowerBound, meanBound - 1);
    else
        return -1;
}

#define MAX_ELEMENTS 100

int main(void) {
    int numbers[MAX_ELEMENTS], userLength, iterIndex, searchElement, searchedIndex;
    
    printf("How many numbers? (integer < %d, expected) > ", MAX_ELEMENTS);
    scanf("%d", &userLength);
    
    printf("Specify all numbers. (space seperated, sorted in ascending order, %d integers expected) > ", userLength);
    for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
        scanf("%d", &numbers[iterIndex]);
    }
    
    printf("Which element to search for? (integer expected) > ");
    scanf("%d", &searchElement);
    
    searchedIndex = binarySearch(numbers, searchElement, 0, userLength - 1);
    
    printf(((searchedIndex != -1) ? "Search completed. Element found at location %d.\n" : "Search completed. Element not found.\n"), searchedIndex + 1);
    
    return 0;
}
