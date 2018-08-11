#include <stdio.h>

// program to write a string to a file on disk
int main() {
    // pointer to file, opens file in write mode
    FILE *fPtr;
    char *fileName = "/Users/swg/Desktop/helloworld.txt";
    fPtr = fopen(fileName, "w");

    // string literal whose character will be written to file
    char *str = "This is a sample message that will be written to and read from the file. Consider saying:\nHello World\n.";

    // write to file and close it
    fprintf(fPtr, "%s", str);
    fclose(fPtr);

    // opens file in read mode
    fPtr = fopen(fileName, "r");
    
    // print file contents until EOF is reached
    char ch;
    while((ch = fgetc(fPtr)) != EOF) {
        printf("%c", ch);
    }

    fclose(fPtr);
    puts("");

    return 0;
}