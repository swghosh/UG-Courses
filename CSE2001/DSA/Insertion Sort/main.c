//
//  main.c
//  Insertion Sort
//
//  Created by Swarup Ghosh on 30/10/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int *insertionSort(int *array, int length) {
    int indexA, indexB, temp;
    for(indexA = 1; indexA < length; indexA++) {
        for(indexB = indexA; indexB > 0 && array[indexB - 1] > array[indexB]; indexB--) {
            temp = array[indexB];
            array[indexB] = array[indexB - 1];
            array[indexB - 1] = temp;
        }
    }
    return array;
}

int main() {
    int *userElements, userLength, iterIndex;
    printf("How many numbers? (integer expected) > ");
    scanf("%d", &userLength);
    
    // will save memory from internal fragmentation
    userElements = (int*) malloc(sizeof(int) * userLength);
    
    printf("Specify all numbers. (space seperated, %d integers expected) > ", userLength);
    for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
        scanf("%d", userElements + iterIndex);
    }
    
    insertionSort(userElements, userLength);
    
    printf("Displaying numbers after performing sort.\n");
    for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
        printf("%d | ", userElements[iterIndex]);
    }
    
    return 0;
}
