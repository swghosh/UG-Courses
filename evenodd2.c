#include <stdio.h>
#include <stdbool.h>

bool even(int);

int main() {
	// take user input
	int number;
	printf("Please specify a number (integer expected)... ");
	scanf("%d", &number);
    // print even or odd
    printf(((even(number)) ? "%d is an even number.\n" : "%d is an odd number.\n"), number);
	return 0;
}

/* function to check a number is even or not */
bool even(int num) {
    return (num % 2) == 0;
}