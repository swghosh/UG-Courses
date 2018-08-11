#include <stdio.h>
#define MAX_ELEMENTS 100

int sumOfArray(int*, int);
int productOfArray(int*, int);

int main() {
    int numbers[MAX_ELEMENTS], userLength, iterIndex;
    printf("How many numbers? (integer < 100, expected) > ");
    scanf("%d", &userLength);

    printf("Specify all numbers. (space seperated, %d integers expected) > ", userLength);
    for(iterIndex = 0; iterIndex < userLength; iterIndex++) {
        scanf("%d", &numbers[iterIndex]);
    }

    printf("Sum and product of all the elements are %d and %d respectively. \n", sumOfArray(numbers, userLength), productOfArray(numbers, userLength));
    return 0;
}

int sumOfArray(int* arrayPointer, int reqdLength) {
    int iterIndex, sum = 0;
    for(iterIndex = 0; iterIndex < reqdLength; iterIndex++) {
        sum += *arrayPointer;
        arrayPointer++;
    }
    return sum;
}

int productOfArray(int* arrayPointer, int reqdLength) {
    int iterIndex, product = 1;
    for(iterIndex = 0; iterIndex < reqdLength; iterIndex++) {
        product *= *arrayPointer;
        arrayPointer++;
    }
    return product;
}