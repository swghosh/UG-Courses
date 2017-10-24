#include<stdio.h>

// program to reverse a number
int main() { 
	// initialise variables
	int number;
	// take user input
	printf("Enter a number: ");
	scanf("%d", &number);
	// reverse the number
	int reverse = 0;
	for(; number > 0; number = number / 10) {
		reverse = (reverse * 10) + (number % 10);
	}
	// print the reversed number
	printf("Reversed number: %d\n", reverse);
	return 0;
}
