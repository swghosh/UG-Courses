#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* menu driven program to check whether a number is prime or not and whether
   it is prime or not */

// function to check whether a number is even or not
bool even(int n) {
	return (n % 2 == 0);
}

// function to check whether a number is prime or not
bool prime(int n) {
	int ctr = 0;
	for(int i = 1; i <= n; i++) {
		ctr = ctr + ((n % i == 0) ? 1 : 0);
	}
	return (ctr == 2);
}

int main() {
	int number, choice;
	// take user input
	puts("Enter an integer number: ");
	scanf("%d", &number);
	// menu
	puts("\nMenu\n1: Prime Number Test\n2: Even Odd Test\n3: Exit\n");
	puts("Enter your choice (1 | 2 | 3) : ");
	scanf("%d", &choice);
	// cases to switch
	switch(choice) {
		case 1:
			// print number is prime or not
			puts(((prime(number)) ? "Prime Number" : "Not Prime Number"));
			break;
		case 2:
			// print number is even or odd
			puts(((even(number)) ? "Even Number" : "Odd Number"));
			break;
		case 3:
			exit(0);
			break;
		default:
			puts("Invalid choice.");
	}
	return 0;
}
