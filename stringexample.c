#include <stdio.h>
#include <stddef.h>

#define STR_LIMIT 10000

// program to find the length of a string input by the user
int main(void) {
    // initialisation
    char str[STR_LIMIT], *ch;
    size_t length = 0;

    // take user input
    printf("Specify a small string (string expected not seperated by spaces, %d characters or less)... ", STR_LIMIT - 1);
    scanf("%s", str);

    // count string length
    ch = str;
    while(*ch != '\0') {
        length++;
        ch++;
    }

    // print length of string
    printf("%lu is the length of the string.\n", length);
    
    return 0;
}