#include <stdio.h>

/* program to subtract two matrices input by the user */
int main(void) {
    
    // take size of 2D array
    int rSize, cSize;
    puts("Specify the order of the matrices. (row size followed by column size) (two integers expected)...");
    scanf("%d %d", &rSize, &cSize);

    // initialise arrays
    int mat1[rSize][cSize], mat2[rSize][cSize], matDiff[rSize][cSize];
    int rIndex, cIndex;

    // take input for first array
    puts("Specify elements for first matrix.");
    for(rIndex = 0; rIndex < rSize; rIndex++) {
        printf("Please specify elements for row %d. (%d integers expected)...", rIndex + 1, cSize);
        for(cIndex = 0; cIndex < cSize; cIndex++) {
            scanf("%d", &mat1[rIndex][cIndex]);
        }
    }

    // take input for second array
    puts("Specify elements for second matrix.");
    for(rIndex = 0; rIndex < rSize; rIndex++) {
        printf("Please specify elements for row %d. (%d integers expected)...", rIndex + 1, cSize);
        for(cIndex = 0; cIndex < cSize; cIndex++) {
            scanf("%d", &mat2[rIndex][cIndex]);
        }
    }

    // perform subtraction
    for(rIndex = 0; rIndex < rSize; rIndex++) {
        for(cIndex = 0; cIndex < cSize; cIndex++) {
            matDiff[rIndex][cIndex] = mat1[rIndex][cIndex] - mat2[rIndex][cIndex];
        }
    }

    // print subtracted array
    puts("\nDifference of matrices: ");
    for(rIndex = 0; rIndex < rSize; rIndex++) {
        printf("| ");
        for(cIndex = 0; cIndex < cSize; cIndex++) {
            printf("%d | ", matDiff[rIndex][cIndex]);
        }
        puts("");
    }

    return 0;
}