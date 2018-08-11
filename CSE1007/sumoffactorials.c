#include <stdio.h>

int main() {
	// variables that will store input range
	int rangeLow, rangeHigh;
	// variables that will store factorial of last number during iteration
	// and sum of factorials in the range
	long int factorial, sumOfFactorial;
	// loop counters
	int indexA, indexB;
	// inital values
	factorial = 1; sumOfFactorial = 0;
	// take user input of range
	printf("Enter the range of numbers seperated by dash: ");
	scanf("%d-%d", &rangeLow, &rangeHigh);
	// calculate factorial of the number before lower range
	for(indexA = 1; indexA < rangeLow; indexA++) {
		factorial = factorial * indexA;
	}
	// calculate sum of factorials
	for(indexB = rangeLow; indexB <= rangeHigh; indexB++) {
		factorial = factorial * indexB;
		sumOfFactorial = sumOfFactorial + factorial;
	}
	// print the sum
	printf("Sum of the factorials of the given range: %ld. \n", sumOfFactorial);
	return 0;
}
