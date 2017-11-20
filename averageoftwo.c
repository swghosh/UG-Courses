#include<stdio.h>

int average(int, int);

int main(void) {
    int numbers[2];
    printf("Please specify two integers (seperated by spaces)... ");
    scanf("%d %d", &numbers[0], &numbers[1]);
    printf("The average of %d and %d is %d.\n", numbers[0], numbers[1], average(numbers[0], numbers[1]));
    return 0;
}

/* calculates the average of two numbers */
int average(int num1, int num2) {
    return (num1 + num2) / 2;
}