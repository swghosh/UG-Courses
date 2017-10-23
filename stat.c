#include<stdio.h>

int main() {
	// take user input of 5 numbers
	int num;
	int index;
	int sum = 0, mean = 0;
	for(index = 0; index < 5; index++) {
		printf("Enter number: ");
		scanf("%d", &num);
		sum = sum + num;
	}
	// calculate mean
	mean = sum / 5;
	// print mean
	printf("Mean: %d\n", mean);
	return 0;
}
