#include <stdio.h>
#include <stddef.h>
// program to search an array element
int main() {
	// user input
	int limit;
	printf("Enter the number of elements in collection: ");
	scanf("%d", &limit);
	// initialise necessary array
	int arr[limit];
	size_t index;
	int search;
	// user input of array elements
	printf("Please enter %d elements (seperated by spaces): \n", limit);
	for(index = 0; index < limit; index++) {
		scanf("%d", &arr[index]);
	}
	// enter search query
	printf("Enter number that is to be searched in collection: ");
	scanf("%d", &search);
	// find the position of searched element
	for(index = 0; index < limit; index++) {
		if(search == arr[index]) 
			printf("%d is present in location %lu of collection.\n", search, index + 1);
	}
	return 0;
}
