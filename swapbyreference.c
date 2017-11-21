#include <stdio.h>

void swapVal(int, int); // swap function, intended to be used with pass by value technique
void swapRef(int*, int*); // swap function, intended to be used with pass by reference technique

int main(void) {
    // take user input of two numbers
    int n1, n2;
    printf("Specify two numbers (seperated by spaces, two integers expected)...");
    scanf("%d %d", &n1, &n2);

    // pass by value
    swapVal(n1, n2);
    printf("\nSwapping using pass by value technique...\nThe values are now %d, %d (unchanged).\n", n1, n2);

    // pass by reference
    swapRef(&n1, &n2);
    printf("\nSwapping using pass by reference technique...\nThe values are now %d, %d (changed).\n", n1, n2);
}

/* function that will take parameter as value */
void swapVal(int num1, int num2) {
    // swapping
    num1 = num2 + num1;
    num2 = num1 - num2;
    num1 = num1 - num2;
}

/* function that will take parameter as reference */
void swapRef(int *num1, int *num2) {
    // swapping
    *num1 = *num2 + *num1;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}