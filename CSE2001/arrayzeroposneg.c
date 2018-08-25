#include <stdio.h>
#define MAX_ELEMENTS 100

int main() {
    int numbers[MAX_ELEMENTS], userLength, iterIndex;
    int positiveCount = 0, negativeCount = 0, zeroCount = 0; 

    printf("How many numbers? (integer < %d, expected) > ", MAX_ELEMENTS);
    scanf("%d", &userLength);

    printf("Specify all numbers. (space seperated, %d integers expected) > ", userLength);
    for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
        scanf("%d", &numbers[iterIndex]);

        if(numbers[iterIndex] > 0) positiveCount++;
        else if(numbers[iterIndex] < 0) negativeCount++;
        else zeroCount++;
    }

    printf("There are %d positive, %d negative number(s) and %d zero(s). \n", positiveCount, negativeCount, zeroCount);
    return 0;
}