#include<stdio.h>

int main() {
	int num, sum;
	for(sum = 0; num != 0; ) {
		printf("Enter a number: (integer) -> ");
		scanf("%d", &num);
		sum = sum + num;
	}
	printf("Sum: %d.\n", sum);
	return 0;
}
