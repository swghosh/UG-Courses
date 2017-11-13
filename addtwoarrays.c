#include <stdio.h>
#include <stddef.h>

#define ARRAY_LIMIT 10

// program to add two arrays and to show 
int main(void) {
    // initialise variables
    int a1[ARRAY_LIMIT] = {0}, a2[ARRAY_LIMIT] = {0}, sum[ARRAY_LIMIT] = {0};
    // take user input of sizes
    printf("Specify sizes of two collections (seperated by spaces; integers 1-10 expected)... ");
    size_t limit1, limit2;
    scanf("%lu %lu", &limit1, &limit2);
    // take user input of array elements
    size_t index;
    printf("Specify %lu integers for first collection (seperated by spaces)... ", limit1);
    for(index = 0; index < limit1; index++) {
        scanf("%d", &a1[index]);
    }
    printf("Specify %lu integers for second collection (seperated by spaces)... ", limit2);
    for(index = 0; index < limit2; index++) {
        scanf("%d", &a2[index]);
    }
    // proceed with addition of arrays
    for(index = 0; index < ((limit1 > limit2) ? limit1 : limit2); index++) {
        sum[index] = a1[index] + a2[index];
    }
    printf("\nSum of two colections\n|");
    // print arrays with sum
    for(index = 0; index < ((limit1 > limit2) ? limit1 : limit2); index++) {
        printf("%d ", sum[index]);
    }
    puts("|");
    return 0;
}