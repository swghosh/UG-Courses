#include <stdio.h>
#include <limits.h>
#define MAX_ELEMENTS 100

int main() {
    int numbers[MAX_ELEMENTS], userLength, iterIndex;
    int max = INT_MIN, min = INT_MAX;
    printf("How many numbers? (integer < %d, expected) > ", MAX_ELEMENTS);
    scanf("%d", &userLength);

    printf("Specify all numbers. (space seperated, %d integers expected) > ", userLength);
    for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
        scanf("%d", &numbers[iterIndex]);

        if(numbers[iterIndex] > max) max = numbers[iterIndex];
        if(numbers[iterIndex] < min) min = numbers[iterIndex];
    }

    printf("Maximum and minimum of all the elements are %d and %d respectively. \n", max, min);
    return 0;
}
