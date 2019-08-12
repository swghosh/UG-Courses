#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

void task(bool);

int main() {
    pid_t pid;
    bool is_parent;

    pid = fork();
    if(pid == 0) is_parent = false;
    else is_parent = true;

    task(is_parent);
    return 0;
}

void task(bool is_parent) {
    char name[10] = "PARENT";
    if(!is_parent) strcpy(name, "CHILD");

    printf("[%s]\n", name);
    printf("\t[%s] Process ID: %d, Parent Process ID: %d.\n", name,  getpid(), getppid());
}