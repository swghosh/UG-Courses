#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "permute.h"

int **max, **need;
int *available, *total;
int num_resources;

void after_permute(int *perm, int len) {

    int iter_a, iter_b, extra;
    int *avail_copy;
    avail_copy = copy_array(available, num_resources);

    for(iter_a = 0; iter_a < len; iter_a++) {
        extra = perm[iter_a];
        for(iter_b = 0; iter_b < num_resources; iter_b++) {
            avail_copy[iter_b] -= need[extra][iter_b];
            if(avail_copy[iter_b] < 0 || avail_copy[iter_b] > total[iter_b]) return;
            avail_copy[iter_b] += max[extra][iter_b];
        }
    }

    printf("Safe Sequence.\n");
    for(iter_a = 0; iter_a < len; iter_a++) {
        printf("[P%d]", perm[iter_a]);
    }
    printf("\n");
}

int main() {
    int num_processes;
    printf("Number of resources (integer expected) -> ");
    scanf("%d", &num_resources);
    printf("Number of processes (integer expected) -> ");
    scanf("%d", &num_processes);

    int index_a, index_b;

    max = (int**) malloc(sizeof(int*) * num_processes);
    need = (int**) malloc(sizeof(int*) * num_processes);
    for(index_a = 0; index_a < num_processes; index_a++) {
        max[index_a] = malloc(sizeof(int) * num_resources);
        need[index_a] = malloc(sizeof(int) * num_resources);
    }

    printf("Process information.\n");
    int extra;
    for(index_a = 0; index_a < num_processes; index_a++) {        
        printf("[P%d] Resources [R%d - R%d] maximum -> ", index_a, 0, num_resources - 1);
        for(index_b = 0; index_b < num_resources; index_b++) {
            scanf("%d", &max[index_a][index_b]);
        }
        printf("[P%d] Resources [R%d - R%d] allocated -> ", index_a, 0, num_resources - 1);
        for(index_b = 0; index_b < num_resources; index_b++) {
            scanf("%d", &extra);
            need[index_a][index_b] = max[index_a][index_b] - extra;
        }
    }

    total = malloc(sizeof(int) * num_resources);
    available = malloc(sizeof(int) * num_resources);

    printf("Maximum available resources.\n");
    printf("[R%d - R%d] max -> ", 0, num_resources - 1);
    for(int index_a = 0; index_a < num_resources; index_a++) {
        scanf("%u", &total[index_a]);
    }

    printf("Currently available resources.\n");
    printf("[R%d - R%d] avail -> ", 0, num_resources - 1);
    for(int index_a = 0; index_a < num_resources; index_a++) {
        scanf("%u", &available[index_a]);
    }

    int *init = malloc(sizeof(int) * 0);
    int *rem = malloc(sizeof(int) * num_processes);
    for(index_a = 0; index_a < num_processes; index_a++) {
        rem[index_a] = index_a;
    }
    permute(init, rem, 0, num_processes, after_permute);

}
