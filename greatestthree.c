#include<stdio.h>

// program to find the greatest of three numbers
int main() {
	// initialise the variables
	int num1, num2, num3;
	// take user input
	puts("Enter three integers: \n");
	scanf("%d %d %d", &num1, &num2, &num3);
	// find the greatest number
	if(num1 > num2 && num1 > num3) {
		printf("%d is the greatest.\n", num1);
	}
	else if(num2 > num1 && num2 > num3) {
		printf("%d is the greatest.\n", num2);
	}
	else {
		printf("%d is the greatest.\n", num3);
	}
	return 0;
}
