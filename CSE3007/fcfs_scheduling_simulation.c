#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct process {
    pid_t pid, ppid;
    int bt, wt, tt;
};
#define PROCESS struct process

int main() {
    pid_t ppid = 0;
    PROCESS *processes; 
    int iter_index, iter_index2, count, proc_sum;

    float awt, att;

    printf("How many processes do you want to enter? (integer expected): ");
    scanf("%d", &count);
    // saves from internal fragmentation
    processes = malloc(sizeof(PROCESS) * count);

    // user input of burst time for each process
    for(iter_index = 0; iter_index < count; iter_index++) {
        printf("--- Process %d ---\n", iter_index);
        processes[iter_index].ppid = ppid;
        processes[iter_index].pid = iter_index + 1;

        processes[iter_index].wt = processes[iter_index].tt = 0;

        printf("Burst Time? (integer expected): ");
        scanf("%d", &processes[iter_index].bt);
    }
    puts("");

    // calculate wait time and turn-around time
    proc_sum = 0;
    for(iter_index = 0; iter_index < count; iter_index++) {
        processes[iter_index].wt = proc_sum;
        proc_sum += processes[iter_index].bt;
        processes[iter_index].tt = proc_sum;
    }

    // show a table of pid, ppid, wt, tt
    puts("FCFS Scheduling");
    printf("-----------------------------------------\n");
    printf("|PID\t|PPID\t|BT\t|WT\t|TT\t|\n");
    printf("-----------------------------------------\n");
    for(iter_index = 0; iter_index < count; iter_index++) {
        printf("|%02d\t|%02d\t|%02d\t|%02d\t|%02d\t|\n", processes[iter_index].pid, processes[iter_index].ppid, 
            processes[iter_index].bt, processes[iter_index].wt, processes[iter_index].tt);
    }
    printf("-----------------------------------------\n");
    puts("");

    // show the gantt chart
    puts("Gantt Chart");
    for(iter_index2 = 0; iter_index2 < ((count * 3) + proc_sum) + 1; iter_index2++) {
        printf("-");
    }
    printf("\n");
    for(iter_index = 0; iter_index < count; iter_index++) {
        printf("|P%d", processes[iter_index].pid);
        for(iter_index2 = 0; iter_index2 < processes[iter_index].bt; iter_index2++) {
            printf(" ");
        }
    }
    printf("|\n");
    for(iter_index2 = 0; iter_index2 < ((count * 3) + proc_sum) + 1; iter_index2++) {
        printf("-");
    }
    printf("\n");
    
    for(iter_index = 0; iter_index < count; iter_index++) {
        printf("%02d ", processes[iter_index].wt);
        for(iter_index2 = 0; iter_index2 < processes[iter_index].bt; iter_index2++) {
            printf(" ");
        }
    }
    printf("%02d", proc_sum);
    puts("");

    awt = att = 0;
    for(iter_index = 0; iter_index < count; iter_index++) {
        awt += processes[iter_index].wt;
        att += processes[iter_index].tt;
    }
    awt = awt / count;
    att = att / count;
    puts("");
    printf("Average WT: %0.2f, Average TT: %0.2f\n", awt, att);

    return 0;
}