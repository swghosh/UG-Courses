#include<stdio.h>

int main() {
	// initialise two variables
	int a, b;
	// take user input of a and b
	printf("Enter for A and B: \n");
	scanf("%d %d", &a, &b);
	// swapping
	// a will now store the sum
	a = a + b;
	// b will store sum - b that is equal to initial a
	b = a - b;
	// a will store sum - b that is equal to initial b
	a = a - b;
	// swapped variables' values are printed
	printf("A and B have values as %d and %d respectively, after swap.\n", a, b);
	return 0;
}

