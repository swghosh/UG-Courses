#include <stdio.h>
#include <unistd.h>

void child();
void parent();

int main() {
    pid_t pid;

    pid = fork();
    if(pid == 0) child();
    else parent();
    return 0;
}

void child() {
    printf("I am a child process! I have pid:%d pid and ppid:%d.\n", getpid(), getppid());
}

void parent() {
    printf("I am the parent process! I have pid:%d pid and ppid:%d.\n", getpid(), getppid());
}