#include <stdio.h>
#include <stddef.h>

#define ARRAY_LIMIT 10

// program to sort elements of an array in ascending order
int main(void) {
    // initialise variables
    int a[ARRAY_LIMIT];
    // take user input of size
    printf("Specify sizes of two collections (seperated by spaces; integers 1-10 expected)... ");
    size_t limit;
    scanf("%lu", &limit);
    // take user input of array elements
    size_t index, index2;
    printf("Specify %lu integers for collection (seperated by spaces)... ", limit);
    for(index = 0; index < limit; index++) {
        scanf("%d", &a[index]);
    }
    // proceed with sorting
    for(index = 0; index < limit - 1; index++) {
        for(index2 = index + 1; index2 < limit; index2++) {
            if(a[index2] < a[index]) {
                // swapping
                a[index2] = a[index2] + a[index];
                a[index] = a[index2] - a[index];
                a[index2] = a[index2] - a[index];
            }
        }
    }
    printf("\nSorted colection\n|");
    // print array after sort
    for(index = 0; index < limit; index++) {
        printf("%d ", a[index]);
    }
    puts("|");
    return 0;
}