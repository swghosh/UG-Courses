#include<stdio.h>

int main() {
	// initialisation
	int number, digits;
	digits = 0;
	// take user input
	printf("Enter an integer: ");
	scanf("%d", &number);
	// calculate number of digits by repetitive division
	for(;number > 0; number = number / 10) digits++;
	// print number of digits
	printf("Number of digits is %d.\n", digits);
	return 0;
}
