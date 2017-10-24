#include<stdio.h>

int main() {
	int number, digits;
	digits = 0;
	printf("Enter an integer: ");
	scanf("%d", &number);
	for(;number > 0; number = number / 10) digits++;
	printf("Number of digits is %d.\n", digits);
	return 0;
}
