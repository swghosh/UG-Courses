#include <stdio.h>

int main() {
	int rangeLow, rangeHigh;
	long int factorial, sumOfFactorial;
	int indexA, indexB;
	factorial = 1; sumOfFactorial = 0;
	puts("Enter the range of numbers seperated by -:");
	scanf("%d-%d", &rangeLow, &rangeHigh);
	for(indexA = 1; indexA < rangeLow; indexA++) {
		factorial = factorial * indexA;
	}
	for(indexB = rangeLow; indexB <= rangeHigh; indexB++) {
		factorial = factorial * indexB;
		sumOfFactorial = sumOfFactorial + factorial;
	}
	printf("Sum of the factorials of the given range: %ld. \n", sumOfFactorial);
	return 0;
}
		
