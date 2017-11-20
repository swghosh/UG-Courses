#include <stdio.h>
#include <stddef.h>

/* program to product two matrices input by the user */
int main(void) {
    
    // take size of first 2D array
    size_t rSize1, cSize1;
    puts("Specify the order of the first matrix. (row size followed by column size) (two integers expected)...");
    scanf("%lu %lu", &rSize1, &cSize1);

    puts("Please make sure that you choose that the order of the second matrix be such that it allow multiplication with the first matrix.");

    // take size of second 2D array
    size_t rSize2, cSize2;
    puts("Specify the order of the second matrix. (row size followed by column size) (two integers expected)...");
    scanf("%lu %lu", &rSize2, &cSize2);

    // check matrix product is possible or not
    if(cSize1 != rSize2) {
        puts("The two matrices cannot be multiplied. Incompatible.");
        return 1;
    }

    // initialise arrays
    int mat1[rSize1][cSize2], mat2[rSize2][cSize2];
    int matProduct[rSize1][cSize2];
    size_t rIndex, cIndex;

    // take input for first array
    puts("Specify elements for first matrix.");
    for(rIndex = 0; rIndex < rSize1; rIndex++) {
        printf("Please specify elements for row %lu. (%lu integers expected)...", rIndex + 1, cSize1);
        for(cIndex = 0; cIndex < cSize1; cIndex++) {
            scanf("%d", &mat1[rIndex][cIndex]);
        }
    }

    // take input for second array
    puts("Specify elements for second matrix.");
    for(rIndex = 0; rIndex < rSize2; rIndex++) {
        printf("Please specify elements for row %lu. (%lu integers expected)...", rIndex + 1, cSize2);
        for(cIndex = 0; cIndex < cSize2; cIndex++) {
            scanf("%d", &mat2[rIndex][cIndex]);
        }
    }

    int partSum;
    size_t extraIndex;
    // perform multiplication
    for(rIndex = 0; rIndex < rSize1; rIndex++) {
        for(cIndex = 0; cIndex < cSize2; cIndex++) {
            partSum = 0;
            for(extraIndex = 0; extraIndex < cSize1; extraIndex++) {
                partSum = partSum + (mat1[rIndex][extraIndex] * mat2[extraIndex][cIndex]);
            }
            matProduct[rIndex][cIndex] = partSum;
        }
    }

    // print product
    puts("\nProduct of matrices: ");
    for(rIndex = 0; rIndex < rSize1; rIndex++) {
        printf("| ");
        for(cIndex = 0; cIndex < cSize2; cIndex++) {
            printf("%d | ", matProduct[rIndex][cIndex]);
        }
        puts("");
    }

    return 0;
}