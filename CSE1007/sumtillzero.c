#include<stdio.h>

int main() {
	// initialisation
	int num, sum;
	// keep adding sum from user input
	// and till user inputs zero
	for(sum = 0; num != 0; ) {
		printf("Enter a number: (integer) -> ");
		scanf("%d", &num);
		sum = sum + num;
	}
	// print the final sum
	printf("Sum: %d.\n", sum);
	return 0;
}
