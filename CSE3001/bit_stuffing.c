#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 5

void show(bool *bits, int len);

int main() {
    bool *input, *output;
    int len, i, j, count;

    input = (bool*) malloc(sizeof(bool) * len);
    output = (bool*) malloc(sizeof(bool) * 2 * len);

    printf("Number of input bits: ");
    scanf("%d", &len);

    printf("Enter bits: ");
    for(i = 0; i < len; i++) {
        scanf("%d", &j);
        if(j == 0) input[i] = false;
        else input[i] = true;
    }

    printf("\nINPUT:\n");
    show(output, j);

    j = 0; count = 0;
    for(i = 0; i < len; i++) {
        output[j] = input[i];
        j++;
        if(input[i]) {
            count++;
        }
        else {
            count = 0;
        }
        if(count == LIMIT) {
            output[j] = false;
            count = 0;
            j++;
        }
    }

    printf("\nOUTPUT:\n");
    show(output, j);
    puts("");
}

void show(bool *bits, int len) {
    int i = 0, d;
    for(i = 0; i < len; i++) {
        if(bits[i]) d = 1;
        else d = 0;

        printf("%d", d);
    }
}