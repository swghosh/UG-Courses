#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

const int R[10] = {1, 2, 3, 3, 3, 4, 4, 4, 4, 4};

void print_bits(bool *data, int len) {
    int iter_index = 0;
    for(iter_index = 0; iter_index < len; iter_index++) {
        if(data[iter_index]) printf("%u ", 1);
        else printf("%u ", 0);
    }
}

int main() {
    unsigned int m, r;
    bool *input_data, *output_data;

    unsigned int iter_index, another_index, count, another_count;
    unsigned int temp;

    printf("How many bits of data do you have? (integer < 10 expected): ");
    scanf("%u", &m);

    input_data = malloc(sizeof(bool) * m);

    printf("Input data bits? (%u space-seperated 0/1 integers expected): \n", m);
    for(iter_index = 0; iter_index < m; iter_index++) {
        scanf("%u", &temp);
        if(temp == 0) input_data[iter_index] = false;
        else input_data[iter_index] = true;
    }

    print_bits(input_data, m);
    printf("\n");

    r = R[m];
    output_data = malloc(sizeof(bool) * (m + r));

    another_index = m - 1;
    count = 0;
    for(iter_index = m + r - 1; iter_index >= 0; iter_index--) {
        if(iter_index == (m + r - 1 - (int) pow(2, count) + 1)) {
            output_data[iter_index] = false;
            count++;
        }
        else {
            output_data[iter_index] = input_data[another_index];
            another_index--;
        }
    }

    print_bits(output_data, m + r);
    printf("\n");

    count = 0;
    for(iter_index = m + r - 1; iter_index >= 0; iter_index--) {
        if(iter_index == (m + r - 1 - (int) pow(2, count) + 1)) {
            
            temp = ~(1 << count);
            for(another_index = 0; another_index < m + r; another_index++) {
                if((temp | (another_index + 1)) == UINT_MAX) {
                    printf("%d\n", another_index + 1);
                }
            }

            count++;
        }
    }
    
}