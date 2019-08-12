#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIMIT 5

void task(bool);

int main() {
    pid_t pid; bool is_parent;

    pid = fork();
    if(pid == 0) {
        is_parent = false;
    }
    else {
        is_parent = true;
    }
    task(is_parent);
    return 0;
}

void task(bool is_parent) {
    int iter_index;
    char name[10] = "PARENT";

    if(!is_parent) strcpy(name, "CHILD");

    printf("[%s] This is the %s process.\n", name, name);
    for(iter_index = 0; iter_index < MAX_LIMIT; iter_index++) {
        printf("\t[%s] count: %d.\n", name, iter_index);
    }
}