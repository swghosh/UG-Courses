#include<stdio.h>

/* program to perform addition, subtraction, multiplication or division on two numbers based
   on user input */
int main() {
	float num1, num2;
	char oper;
	// take user input
	printf("Enter a number followed by (+ | - | * | /) followed by another number: \n");
	scanf("%f %c %f", &num1, &oper, &num2);
	// perform operation
	switch (oper) {
		// in case of addition
		case '+':
			printf("%f + %f = %f\n", num1, num2, (num1 + num2));
			break;
		// in case of subtraction
		case '-':
			printf("%f - %f = %f\n", num1, num2, (num1 - num2));
			break;
		// in case of multiplication
		case '*':
			printf("%f * %f = %f\n", num1, num2, (num1 * num2));
			break;
		// in case of division
		case '/':
			printf("%f / %f = %f\n", num1, num2, (num1 / num2));
			break;
		// in case of invalid operator
		default:
			printf("%f %c %f is an invalid input\n", num1, oper, num2);
	}
	return 0;
}

