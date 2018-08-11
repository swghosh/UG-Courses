#include<stdio.h>
#include<stdbool.h>
#include<math.h>
// program to find octal, binary, hexadecimal equivalent of a number
int main() {
    int decimal, temp, index;
    long int binary, octal;
    // user input
    printf("Enter a number: ");
    scanf("%d", &decimal);
    // conversion to binary
    binary = 0;
    index = 0;
    for(temp = decimal; temp > 0; temp = temp / 2) {
        binary = binary + (long int)(pow(10, index++) * (temp % 2));
    }
    printf("The binary equivalent of %d is %ld.\n", decimal, binary);
    // conversion to octal
    octal = 0;
    index = 0;
    for(temp = decimal; temp > 0; temp = temp / 8) {
        octal = octal + (long int)(pow(10, index++) * (temp % 8));
    }
    printf("The octal equivalent of %d is %ld.\n", decimal, octal);
    // uses the format specifier %X in printf to print hexadecimal equivalent of an integer
    printf("The hexadecimal equivalent of %d is %X.\n", decimal, decimal);
    return 0;
}