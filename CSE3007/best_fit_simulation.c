#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

struct process {
    pid_t pid;
    unsigned int mem_reqd;
    bool is_allocated;
    int block_id;
};
#define PROCESS struct process

struct memory_block {
    int id;
    unsigned int total_mem, free_mem;
};
#define BLOCK struct memory_block

// sort memory blocks in ascending order
// on the basis of free memory
void sort_blocks(BLOCK *blocks, int b_count) {
    BLOCK temp;
    int index_a, index_b;
    for(index_a = 0; index_a < b_count - 1; index_a++) {
        for(index_b = 0; index_b < b_count - index_a - 1; index_b++) {
            if((blocks + index_b)->free_mem > (blocks + index_b + 1)->free_mem) {
                temp = *(blocks + index_b);
                *(blocks + index_b) = *(blocks + index_b + 1);
                *(blocks + index_b + 1) = temp;
            }
        }
    }
}

int main() {
    int p_count, b_count;
    int iter_index, iter_index2;
    PROCESS *processes; BLOCK *blocks;

    printf("How many processes do you want to enter? (integer expected): ");
    scanf("%d", &p_count);
    // saves from internal fragmentation
    processes = malloc(sizeof(PROCESS) * p_count);

    // user input of memory requirement for each process
    for(iter_index = 0; iter_index < p_count; iter_index++) {
        printf("--- Process %d ---\n", iter_index + 1);
        processes[iter_index].pid = iter_index + 1;

        printf("Memory Requirement? (in K, unsigned integer expected): ");
        scanf("%d", &processes[iter_index].mem_reqd);

        processes[iter_index].is_allocated = false;
        processes[iter_index].block_id = 0;
    }
    puts("");

    printf("How many memory blocks do you want to enter? (integer expected): ");
    scanf("%d", &b_count);
    // saves from internal fragmentation
    blocks = malloc(sizeof(BLOCK) * p_count);

    // user input of available memory in each block / hole
    for(iter_index = 0; iter_index < b_count; iter_index++) {
        printf("--- Block %d ---\n", iter_index + 1);
        blocks[iter_index].id = iter_index + 1;

        printf("Available memory? (in K, unsigned integer expected): ");
        scanf("%d", &blocks[iter_index].total_mem);

        blocks[iter_index].free_mem = blocks[iter_index].total_mem;
    }
    puts("");

    for(iter_index = 0; iter_index < p_count; iter_index++) {
        sort_blocks(blocks, b_count);
        for(iter_index2 = 0; iter_index2 < b_count; iter_index2++) {
            if(!processes[iter_index].is_allocated 
                && blocks[iter_index2].free_mem >= processes[iter_index].mem_reqd) {
                processes[iter_index].block_id = blocks[iter_index2].id;
                processes[iter_index].is_allocated = true;
                blocks[iter_index2].free_mem -= processes[iter_index].mem_reqd;
            }
        }
    }

    // show details in tabular form
    // for processes and blocks
    puts("Best Fit Allocation");
    printf("---------------------------------\n");
    printf("|PID\t|MEM\t|BLOCK\t|ALLOC\t|\n");
    printf("---------------------------------\n");
    for(iter_index = 0; iter_index < p_count; iter_index++) {
        printf("|P%02d\t|%02dK\t|B%02d\t|%s\t|\n", processes[iter_index].pid, 
            processes[iter_index].mem_reqd, processes[iter_index].block_id, 
            (processes[iter_index].block_id != 0 ? "Yes" : "No"));
    }
    printf("---------------------------------\n");
    puts("");

    printf("---------------------------------\n");
    printf("|BLOCK\t|TOTAL\t|AVAILABLE\t|\n");
    printf("---------------------------------\n");
    for(iter_index = 0; iter_index < b_count; iter_index++) {
        printf("|B%02d\t|%02dK\t|%02dK\t\t|\n", blocks[iter_index].id, 
            blocks[iter_index].total_mem, blocks[iter_index].free_mem);
    }
    printf("---------------------------------\n");
    puts("");

    return 0;
}