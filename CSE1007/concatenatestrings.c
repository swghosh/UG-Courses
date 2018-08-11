#include <stdio.h>
#include <string.h>

#define STR_LIMIT 10000

// program to concatenate two strings
int main(void) {
    // initialisation
    char str1[STR_LIMIT], str2[STR_LIMIT];

    // take user input
    printf("Specify two small strings (strings seperated by spaces, %d characters or less in total)... ", STR_LIMIT - 1);
    scanf("%s %s", str1, str2);

    strcat(str1, str2);

    // print length of string
    printf("%s\nis the string obtained after concatenation.\n", str1);
    
    return 0;
}