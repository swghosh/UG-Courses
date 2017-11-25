#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* lowercase(char *str) {
    char *newStr = (char*) malloc(sizeof(char) * strlen(str) + 1);
    char *bak = newStr;
    while(*str != '\0') {
        *bak = (char)tolower(*str);
        bak++;
        str++;
    }
    *bak = '\0';
    return newStr;
}

int main(void) {
    struct materials {
        char **primary;
        char **secondary;
    };
    struct dimensions {
        int mmLength, mmWidth, mmHeight;
    };
    struct product {
        struct dimensions dimensions;
        char *name;
        float kgWeight;
        struct materials materials;
    };

    #define PRODUCT struct product
    typedef struct product Product;

    size_t size = sizeof(PRODUCT);
    printf("Size of PRODUCT is %lu bytes\n", size);

    size = sizeof(Product);
    printf("Size of Product is %lu bytes\n", size);

    char *primaryMat[] = {"Wood", "Aluminium"};
    char *secondaryMat[] = {"Formica", "Tape"};

    Product prod1 = {
        140, 330, 290, "Laptop Stand", 2.0, primaryMat, secondaryMat
    };
    
    printf("Memory address of product1 is %p\n", &prod1);

    printf("A product named %s with dimensions %dmm x %dmm x %dmm, weighing %.2fkg using primary materials %s, %s and secondary materials %s, %s was fabricated.\n",
            prod1.name,
            prod1.dimensions.mmHeight,
            prod1.dimensions.mmLength,
            prod1.dimensions.mmWidth,
            prod1.kgWeight,
            lowercase(prod1.materials.primary[0]),
            lowercase(prod1.materials.primary[1]),
            lowercase(prod1.materials.secondary[0]),
            lowercase(prod1.materials.secondary[1])
            );

    return 0;
}