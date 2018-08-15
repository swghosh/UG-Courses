#include <stdio.h>
#define MAX_ELEMENTS 100

long sumOfArray(int*, int);
long productOfArray(int*, int);

int main() {
    int numbers[MAX_ELEMENTS], userLength, iterIndex;
    printf("How many numbers? (integer < %d, expected) > ", MAX_ELEMENTS);
    scanf("%d", &userLength);

    printf("Specify all numbers. (space seperated, %d integers expected) > ", userLength);
    for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
        scanf("%d", &numbers[iterIndex]);
    }

    printf("Sum and product of all the elements are %ld and %ld respectively. \n", sumOfArray(numbers, userLength), productOfArray(numbers, userLength));
    return 0;
}

long sumOfArray(int* arrayPointer, int reqdLength) {
    int iterIndex; long sum = 0;
    for(iterIndex = 0; iterIndex < reqdLength; iterIndex++) {
        sum += *arrayPointer;
        arrayPointer++;
    }
    return sum;
}

long productOfArray(int* arrayPointer, int reqdLength) {
    int iterIndex; long product = 1;
    for(iterIndex = 0; iterIndex < reqdLength; iterIndex++) {
        product *= *arrayPointer;
        arrayPointer++;
    }
    return product;
}