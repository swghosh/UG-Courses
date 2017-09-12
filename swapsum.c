#include<stdio.h>
int main() {
	int num1, num2;
	printf("\nEnter first number: ");
	scanf("%d", &num1);
	printf("\nEnter second number: ");
	scanf("%d", &num2);
	// perform swap
	num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;
	// perform addition
	int sum = num1 + num2;
	// print sum
	printf("\nSum: %d + %d = %d\n", num1, num2, sum);
	return 0;
}
