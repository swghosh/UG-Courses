#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LIMIT 1000

int main(void) {

    // initialise file pointer and variables to store pathname and filename
    FILE *filePointer;
    char itCh, *path, *fullPath;
    char *filename = "whateveryoutyped.txt";

    // allocate memory to store path string
    path = malloc(sizeof(char) * STRING_LIMIT);

    // compiling the program on a Apple Macintosh system and deciding the path where to store the file
    #ifdef __APPLE__
    if(getenv("HOME")) {
        strcat(path, getenv("HOME"));
        strcat(path, "/Desktop/");
    }
    else if(getenv("TMPDIR")) {
        strcat(path, getenv("TMPDIR"));
        strcat(path, "/");
    }
    else {
        strcat(path, "/tmp/");
    }

    // compiling the program on a Linux system and deciding the path where to store the files
    #elif __linux__
    if(getenv("HOME")) {
        strcat(path, getenv("HOME"));
        strcat(path, "/Desktop/");
    }
    else if(getenv("TMPDIR")) {
        strcat(path, getenv("TMPDIR"));
        strcat(path, "/");
    }
    else {
        strcat(path, "/tmp/");
    }

    // compiling the program on a system running Turbo C and deciding the path where to store the files
    #elif __TURBOC__
    strcat(path, ".\\");

    // compiling the program on MinGW for Windows and deciding the path where to store the files
    #elif __MINGW32__
    if(getenv("HOMEPATH")) {
        strcat(path, getenv("HOMEPATH") + "\\Desktop\\");
    }
    else if(getenv("TEMP")) {
        strcat(path, getenv("TEMPDIR") + "\\");
    }
    else {
      strcat(path, ".\\");
    }

    // compiling the program on a Windows system and deciding the path where to store the files
    #elif __WIN32__
    if(getenv("HOMEPATH")) {
        strcat(path, getenv("HOMEPATH") + "\\Desktop\\");
    }
    else if(getenv("TEMP")) {
        strcat(path, getenv("TEMPDIR") + "\\");
    }
    else {
      strcat(path, ".\\");
    }

    // compiling the program on some other system and deciding the path where to store the files
    #else
    strcat(path, ".\\");

    #endif

    // allocate memory to store string of full path to file
    fullPath = malloc(sizeof(char) * (strlen(path) + strlen(filename) + 1));
    // concatenate in order to store the full file path
    strcat(fullPath, path);
    strcat(fullPath, filename);

    // free up the memory utilised by path string previously
    free(path);

    // print a message and the file path
    printf("This program will start writing to file %s based on whatever you type underneath until EOF is reached / passed.\n\n", fullPath);

    // open the file for writing
    filePointer = fopen(fullPath, "w");
    // write characters to file based on user input until EOF is reached / passed
    while((itCh = getchar()) != EOF) {
      fputc(itCh, filePointer);
    }
    // close the file
    fclose(filePointer);

    return 0;
}
