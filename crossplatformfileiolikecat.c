#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LIMIT 1000

int main(void) {

    FILE *filePointer;
    char itCh, *path, *fullPath;
    char *filename = "whateveryoutyped.txt";

    path = malloc(sizeof(char) * STRING_LIMIT);

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

    #elif __TURBOC__
    strcat(path, ".\\");

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

    #else
    strcat(path, ".\\");

    #endif

    fullPath = malloc(sizeof(char) * (strlen(path) + strlen(filename) + 1));
    strcat(fullPath, path);
    strcat(fullPath, filename);

    free(path);

    printf("This program will start writing to file %s based on whatever you type underneath until EOF is reached / passed.\n\n", fullPath);

    filePointer = fopen(fullPath, "w");
    while((itCh = getchar()) != EOF) {
      fputc(itCh, filePointer);
    }
    fclose(filePointer);

    return 0;
}
