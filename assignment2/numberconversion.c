#include<stdio.h>
// program to find octal, binary, hexadecimal equivalent of a number
int main() {
    int decimal, binary, octal, hexadecimal, temp;
    // user input
    printf("Enter a number: ");
    scanf("%d", &decimal);
    // conversion to binary
    binary = 0;
    for(temp = decimal; temp > 0; temp = temp / 2) {

    }
    printf("The binary equivalent of %d is %d.\n", decimal, binary);
    // conversion to octal
    octal = 0;
    for(temp = decimal; temp > 0; temp = temp / 8) {

    }
    printf("The octal equivalent of %d is %d.\n", decimal, octal);
    // conversion to hexadecimal
    hexadecimal = 0;
    for(temp = hexadecimal; temp > 0; temp = temp / 16) {
        
    }
    return 0;
}