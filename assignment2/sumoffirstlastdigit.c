#include<stdio.h>
// program to find the sum of first and last digit of number input by user
int main() {
    // initialise required variabless
    int number, temp, sum;
    // take user input
    printf("Enter a number (integer) -> ");
    scanf("%d", &number);
    // calculate sum of first and last digit only
    sum = 0;
    for(temp = number; temp > 0; temp = temp / 10) {
        // in case of first / last digit only
        if(temp == number || temp / 10 == 0) 
            sum = sum + (temp  % 10);
    }
    // print the required sum
    printf("Sum of first and last digit of %d is %d.\n", number, sum);
    return 0;
}