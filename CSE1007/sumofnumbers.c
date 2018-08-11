#include <stdio.h>
#include <stddef.h>

/* function prototype for sum */
int sum(int*, size_t);

/* main method that is to be executed at runtime */
int main(void) {
    // take user input of sizes
    printf("Specify how many numbers you want to enter? (integer expected)... ");
    size_t length;
    scanf("%lu", &length);
    int a1[length];
    // take user input of array elements
    size_t index;
    printf("Specify %lu integers (seperated by spaces)... ", length);
    for(index = 0; index < length; index++) {
        scanf("%d", &a1[index]);
        if(a1[index] == 0) {
            printf("You've entered zero at location %lu, so program will exit..\n", (index + 1));
            return 1;
        }
    }
    // print value of sum
    int* numbers = a1;
    printf("Sum of the given numbers is %d.\n", sum(numbers, length));
    return 0;
}

/* calculate the average of few numbers by passing a pointer to the array and its number of elements */
int sum(int* numbers, size_t length) {
    size_t index;
    int sum = 0;
    // calculate sum
    for(index = 0; index < length; index++) {
        sum = sum + numbers[index];
    }
    return sum;
}