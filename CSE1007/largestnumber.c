#include <stdio.h>
#include <limits.h>

// program to find the largest number in an array
int main() {
	int arr[100], index, limit, largest;
	// take user input
	puts("Enter the number of elements (1-100): ");
	scanf("%d", &limit);
	printf("Please enter %d number (seperated by spaces): \n", limit);
	largest = INT_MIN;
	// user input of numbers and calculating largest
	for(index = 0; index < limit; index++) {
		scanf("%d", &arr[index]);
		if(arr[index] > largest) largest = arr[index];
	}
	// print the calculated largest
	printf("Largest Number is %d.\n", largest);
	return 0;
}
