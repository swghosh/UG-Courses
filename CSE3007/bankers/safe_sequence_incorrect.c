#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

#include "permute.h"

PROCESS *processes;
RESOURCE *res;

int *available, *max, len_resources;

void after_permute(int *perm, int len) {

    int iter, iter_a;
    
    for(iter = 0; iter < len_resources; iter++) {
        available[iter] = res[iter].avail;
        max[iter] = res[iter].max;
    }

    print_int_array(available, len_resources);
    print_int_array(max, len_resources);

    for(iter = 0; iter < len_resources; iter++) {
        for(iter_a = 0; iter_a < len; iter_a++) {
            available[iter] -= processes[iter_a].resources[iter].need;
            available[iter] += processes[iter_a].resources[iter].max;
        }
    }

    print_int_array(available, len_resources);
    print_int_array(max, len_resources);

    printf("Safe Sequence.\n");
    for(iter = 0; iter < len; iter++) {
        printf("[P%d]", perm[iter]);
    }
    printf("\n");
}

int main() {
    size_t num_processes, num_resources;
    printf("Number of resources (integer expected) -> ");
    scanf("%ld", &num_resources);
    printf("Number of processes (integer expected) -> ");
    scanf("%ld", &num_processes);

    processes = malloc(num_processes * sizeof(PROCESS));

    printf("Process information.\n");
    int index_a, index_b;
    for(index_a = 0; index_a < num_processes; index_a++) {
        processes[index_a].id = (unsigned int) index_a;
        processes[index_a].resources = malloc(num_resources * sizeof(RESOURCE));
        
        printf("[P%d] Resources [R%d - R%ld] allocated -> ", index_a, 0, num_resources - 1);
        for(index_b = 0; index_b < num_resources; index_b++) {
            processes[index_a].resources[index_b].id = (unsigned int) index_b;
            scanf("%u", &processes[index_a].resources[index_b].alloc);
        }

        printf("[P%d] Resources [R%d - R%ld] maximum -> ", index_a, 0, num_resources - 1);
        for(index_b = 0; index_b < num_resources; index_b++) {
            scanf("%u", &processes[index_a].resources[index_b].max);
            processes[index_a].resources[index_b].need = processes[index_a].resources[index_b].max - processes[index_a].resources[index_b].alloc;
        }
    }

    res = malloc(num_resources * sizeof(RESOURCE));

    printf("Maximum available resources.\n");
    printf("[R%d - R%ld] max -> ", 0, num_resources - 1);
    for(int index_a = 0; index_a < num_resources; index_a++) {
        res[index_a].id = (unsigned int) index_a;
        scanf("%u", &res[index_a].max);
    }

    printf("Total available resources.\n");
    printf("[R%d - R%ld] avail -> ", 0, num_resources - 1);
    for(int index_a = 0; index_a < num_resources; index_a++) {
        scanf("%u", &res[index_a].avail);
    }

    // reqd variables after permute
    available = malloc(sizeof(int) * num_resources);
    max = malloc(sizeof(int) * num_resources);
    len_resources = num_resources;

    int *init = malloc(sizeof(int) * 0);
    int *rem = malloc(sizeof(int) * num_processes);
    for(index_a = 0; index_a < num_processes; index_a++) {
        rem[index_a] = index_a;
    }
    permute(init, rem, 0, num_processes, after_permute);

}
