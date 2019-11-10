#include <stdio.h>
#include <stdlib.h>

#include "permute.h"

struct resource {
    unsigned int id;
    unsigned int alloc, max;
    unsigned int need, avail;
};
#define RESOURCE struct resource

struct process {
    unsigned int id;
    RESOURCE *resources;
};
#define PROCESS struct process

int main() {
    size_t num_processes, num_resources;
    printf("Number of resources (integer expected) -> ");
    scanf("%ld", &num_resources);
    printf("Number of processes (integer expected) -> ");
    scanf("%ld", &num_processes);

    PROCESS *processes;
    processes = malloc(num_processes * sizeof(PROCESS));

    printf("Process information.\n");
    int index_a, index_b;
    for(index_a = 0; index_a < num_processes; index_a++) {
        processes[index_a].id = (unsigned int) index_a;
        processes[index_a].resources = malloc(num_resources * sizeof(RESOURCE));
        
        printf("[P%d] Resources: \n", index_a);
        for(index_b = 0; index_b < num_resources; index_b++) {
            processes[index_a].resources[index_b].id = (unsigned int) index_b;
            printf("[P%d] [R%d] allocated -> ", index_a, index_b);
            scanf("%u", &processes[index_a].resources[index_b].alloc);
            printf("[P%d] [R%d] maximum -> ", index_a, index_b);
            scanf("%u", &processes[index_a].resources[index_b].max);

            processes[index_a].resources[index_b].need = processes[index_a].resources[index_b].max - processes[index_a].resources[index_b].alloc;
        }
    }

    RESOURCE *res;
    res = malloc(num_resources * sizeof(RESOURCE));

    printf("Maximum available resources.\n");
    for(int index_a = 0; index_a < num_resources; index_a++) {
        res[index_a].id = (unsigned int) index_a;
        printf("[R%d] max -> ", index_a);
        scanf("%u", &res[index_a].max);
    }

    printf("Total available resources.\n");
    for(int index_a = 0; index_a < num_resources; index_a++) {
        res[index_a].id = (unsigned int) index_a;
        printf("[R%d] avail -> ", index_a);
        scanf("%u", &res[index_a].avail);
    }

    
}
