#include <stdio.h>
#include <stddef.h>

/* function prototype for mean and median */
float mean(int*, size_t);
float median(int*, size_t);

/* main method that is to be executed at runtime */
int main(void) {
    // take user input of sizes
    printf("Specify how many numbers you want to enter? (seperated by spaces, integer expected)... ");
    size_t length;
    scanf("%lu", &length);
    int a1[length];
    // take user input of array elements
    size_t index;
    printf("Specify %lu integers (seperated by spaces)... ", length);
    for(index = 0; index < length; index++) {
        scanf("%d", &a1[index]);
    }
    // make a pointer to the required array
    int* numbers = a1;
    // print values of mean and median by calling respective functions
    printf("Mean = %.2f, median = %.2f.\n", mean(numbers, length), median(numbers, length));
    return 0;
}

/* selection sort a given array of integers by passing a pointer to the array and its number of elements */
int* selectionSort(int* numbers, size_t length) {
    size_t index, index2;
    // selection sort
    for(index = 0; index < length - 1; index++) {
        for(index2 = index + 1; index2 < length; index2++) {
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

/* calculate the mean of few numbers by passing a pointer to the array and its number of elements */
float mean(int* numbers, size_t length) {
    int sum = 0;
    size_t index;
    // add all the elements in the array
    for(index = 0; index < length; index++) {
        sum = sum + numbers[index];
    }
    // return the mean
    return ((float)sum / length);
}

/* calculate the median of few numbers by passing a pointer to the array and its number of elements */
float median(int* numbers, size_t length) {
    // sort the array so as to obtain a sorted array
    numbers = selectionSort(numbers, length);
    // find median in case of even number of elements
    if(length % 2 == 0) {
        return (float)(numbers[(length / 2) - 1] + numbers[(length / 2)]) / 2;
    }
    // find mode in case of odd number of elements
    else {
        return (float)numbers[((length + 1) / 2) - 1];
    }
}