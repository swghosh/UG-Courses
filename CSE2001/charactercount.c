#include <stdio.h>

#define MAX_LENGTH 100

int countOccurence(char *userString, char searchChar);

int main() {
    char userString[MAX_LENGTH], searchChar;

    printf("Specify a string... (characters < %d) > ", MAX_LENGTH - 1);
    scanf("%s", userString);

    printf("Specify character to count occurences... (character expected) > ");
    scanf(" %c", &searchChar);

    printf("%c was found %d number of times.\n", searchChar, countOccurence(userString, searchChar));
}

// count the number of occurences of `searchChar`
// in the given `userString`
int countOccurence(char *userString, char searchChar) {
    int iterIndex = 0, count = 0;
    while(*(userString + iterIndex) != '\0') {
        if(*(userString + iterIndex) == searchChar) count++;
        iterIndex++;
    }
    return count;
}