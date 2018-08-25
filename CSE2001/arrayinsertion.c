#include <stdio.h>
#define MAX_ELEMENTS 100

int main() {
    int numbers[MAX_ELEMENTS], userLength, iterIndex;
    int insertElement, insertPosition;

    printf("How many numbers? (integer < %d, expected) > ", MAX_ELEMENTS);
    scanf("%d", &userLength);

    printf("Specify all numbers. (space seperated, %d integers expected) > ", userLength);
    for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
        scanf("%d", &numbers[iterIndex]);
    }

    printf("Specify a number to insert. (integer expected) > ");
    scanf("%d", &insertElement);

    printf("Specify insertion location. (integer <= %d expected) > ", userLength + 1);
    scanf("%d", &insertPosition);

    if(insertPosition <= userLength + 1) {
        insertPosition--;
        for(iterIndex = userLength - 1; iterIndex >= insertPosition; iterIndex--) {
            numbers[iterIndex + 1] = numbers[iterIndex];
        }

        numbers[insertPosition] = insertElement;
        userLength++;
    }
    else {
        puts("Insertion not possible at this location.");
    }
    
    printf("\nNumbers: ");
    for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
        printf("%d | ", numbers[iterIndex]);
    }
    printf("\n");

    return 0;
}