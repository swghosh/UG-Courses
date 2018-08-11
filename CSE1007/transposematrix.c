#include <stdio.h>
#include <stddef.h>

/* program to product two matrices input by the user */
int main(void) {
    
    // take size of 2D array
    size_t rSize, cSize;
    puts("Specify the order of the matrix. (row size followed by column size) (two integers expected)...");
    scanf("%lu %lu", &rSize, &cSize);

    // initialise arrays
    int mat[rSize][cSize], transMat[cSize][rSize];
    size_t rIndex, cIndex;

    // take input for  array
    puts("Specify elements for matrix.");
    for(rIndex = 0; rIndex < rSize; rIndex++) {
        printf("Please specify elements for row %lu. (%lu integers expected)...", rIndex + 1, cSize);
        for(cIndex = 0; cIndex < cSize; cIndex++) {
            scanf("%d", &mat[rIndex][cIndex]);
        }
    }
    
    // perform transposition
    for(rIndex = 0; rIndex < rSize; rIndex++) {
        for(cIndex = 0; cIndex < cSize; cIndex++) {
            transMat[cIndex][rIndex] = mat[rIndex][cIndex];
        }
    }

    // print transposed matrix
    puts("\nTransposed matrix: ");
    for(rIndex = 0; rIndex < cSize; rIndex++) {
        printf("| ");
        for(cIndex = 0; cIndex < rSize; cIndex++) {
            printf("%d | ", transMat[rIndex][cIndex]);
        }
        puts("");
    }

    return 0;
}