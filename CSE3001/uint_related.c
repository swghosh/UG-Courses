#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int x, i;
    x = 1;
    x = ~(x << 0);
    printf("%u\n", x);
    for(i = 1; i <= 11; i++) {
        printf("%u: %u\n", i, i | x);
    }
    
    printf("UINTMAX: %u\n", UINT_MAX);
    printf("int: %ld bytes\n", sizeof(int));
}