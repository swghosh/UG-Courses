#include<stdio.h>
int main() {
	int num;
	// take user input
	printf("Enter an integer: ");
	scanf("%d", &num);
	// calculate the factorial using a loop
	int factorial = 1;
	for(int i = num; i >= 1; i--) factorial = factorial * i;
	printf("Factorial of %d is %d.\n", num, factorial);
	return 0;
}
