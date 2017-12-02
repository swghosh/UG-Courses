#include <stdio.h>
#include <stdlib.h>

// program to take user input until user gives EOF and write the input contents to a file
int main(void) {

    // pointer to file
    FILE *file;
    // will store filename
    char *filename;
    // other initialisation
    char ch;
    int count;
    
    // assigns filename a string literal
    filename = "whateveryoutyped.txt";
    // opens file in write mode
    file = fopen(filename, "w");
    // initialises ch, count to zeroes
    ch = '\0';
    count = 0;

    // loop till EOF is entered
    while(ch != EOF) {
        // print the respective character to the file
        fprintf(file, "%c", ch);
        // get a character from stdin
        ch = getc(stdin);
        // increment count
        count++;
    }

    // close the file
    fclose(file);

    // print number of bytes written to file
    printf("%d bytes of text written to file %s.\n", count, filename);

    return 0;
}