#include<stdio.h>

int main() {
	printf("Enter for n: ");
	int n;
	scanf("%d", &n);
	int sum = 0;
	int ctr = 1;
	for(ctr = 1; ctr <= n; ctr++) {
		sum = sum + ctr;
	}
	printf("Sum: %d.\n", sum);
	return 0;
}
