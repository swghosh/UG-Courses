#include<stdio.h>
int main() {
	// take user input
	int number;
	printf("\n Enter a number: ");
	scanf("%d", &number);
	// perform check
	if(number % 2 == 0) {
		printf("\n Even Number\n");
	}
	else {
		printf("\n Odd Number\n");
	}
	return 0;
}
