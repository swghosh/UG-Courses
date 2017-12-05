#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define character array limit for storing the strings
#define STR_LIMIT 10000

/* function prototypes to remove duplicates in a string and to get frequency of highest occuring character */
char *removeDuplicates(char*);
int frequencyOfDuplicate(char*);

// main method that is to be executed
int main(void) {
    // initialisations
    char userString[STR_LIMIT];

    // user input of a string
    printf("Specify a string (%d characters or less, not seperated by any space)... ", STR_LIMIT - 1);
    scanf("%s", userString);

    // print the string with duplicates removed and frequency of the highest occuring character in it
    printf("The string after removing the duplicates is\n%s\nand the frequency of the highest occuring character is %d.\n", removeDuplicates(userString), frequencyOfDuplicate(userString));
    
    return 0;
}

/* remove duplicate characters from a string
 * Assumption: string has ASCII characters having char codes only from 0-255
*/
char *removeDuplicates(char *str) {
    // initialisations
    char *str2, itCh[2];
    // store frequency of occurence of ASCII characters
    int frequencies[256] = {0};
    // allocate memory to str2 where new string will be stored
    str2 = malloc(sizeof(char) * STR_LIMIT);

    // iterate through each element in string
    itCh[1] = '\0';
    while((itCh[0] = *str++) != '\0') {
        // increment occurence of a character
        frequencies[(int)(itCh[0])]++;
        // concatenate string with iterated character only when it has not occured before
        if(frequencies[(int)(itCh[0])] <= 1) {
            strcat(str2, itCh);
        }
    }

    // return the string containing no duplicate characters
    return str2;
}

/* get the frequency of the highest occuring character from a string
 * Assumption: string has ASCII characters having char codes only from 0-255
*/
int frequencyOfDuplicate(char *str) {
    // initialisations
    char chIt;
    // store frequency of occurence of ASCII characters, and max frequency
    int frequencies[256] = {0}, max = 0;
    // iterate through each element in string
    while((chIt = *str++) != '\0') {
        // increment occurence of a character
        frequencies[(int)chIt]++;
        // update max frequency in case character occurence is high
        if(frequencies[(int)chIt] > max) {
            max = frequencies[(int)chIt];
        }
    }
    // return the frequency of highest occuring character
    return max;
}