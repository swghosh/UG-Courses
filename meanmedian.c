#include <stdio.h>
#include <stddef.h>

int mean(int*, size_t);
int median(int*, size_t);

int main(void) {
    // take user input of sizes
    printf("Specify how many numbers you want to enter? (seperated by spaces; integers expected)... ");
    size_t limit;
    scanf("%lu", &limit);
    int a1[limit];
    // take user input of array elements
    size_t index;
    printf("Specify %lu integers (seperated by spaces)... ", limit);
    for(index = 0; index < limit; index++) {
        scanf("%d", &a1[index]);
    }
    int* numbers = a1;
    printf("Mean = %d, median = %d.\n", mean(numbers, limit), median(numbers, limit));
    return 0;
}

int* selectionSort(int* numbers, size_t limit) {
    size_t index, index2;
    for(index = 0; index < limit - 1; index++) {
        for(index2 = index + 1; index2 < limit; index2++) {
            if(numbers[index2] < numbers[index]) {
                // swapping
                numbers[index2] = numbers[index2] + numbers[index];
                numbers[index] = numbers[index2] - numbers[index];
                numbers[index2] = numbers[index2] - numbers[index];
            }
        }
    }
    return numbers;
}

int mean(int* numbers, size_t limit) {
    int sum = 0;
    size_t index;
    for(index = 0; index < limit; index++) {
        sum = sum + numbers[index];
    }
    return (sum / limit);
}

int median(int* numbers, size_t limit) {
    if(limit % 2 == 0) {
        return (numbers[(limit / 2)] + numbers[(limit / 2) + 1]) / 2;
    }
    else {
        return numbers[(limit + 1) / 2];
    }
}