#include<stdio.h>
#include<stddef.h>

#define A_SIZE 20

int main(void) {
	int a[A_SIZE];
	size_t index;
	// initialise values of array
	for(index = 0; index < A_SIZE; index++) {
		if(index == 0) {
			a[index] = 1;
			continue;
		}
		a[index] = 2 * a[index - 1];
	}
	// print values
	printf("Array storing exponents of 2:\n");
	puts("----------------");
	printf("|%5s | %6s|\n", "Index", "Value");
	puts("----------------");
	for(index = 0; index < A_SIZE; index++) {
		printf("|%5u | %6d|\n", index, a[index]);
	}
	puts("----------------");
	return 0;
}
