#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();
    if(pid == 0) {
        printf("I am a child process!\n");
    }
    else {
        printf("I am the parent process!\n");
    }
    return 0;
}