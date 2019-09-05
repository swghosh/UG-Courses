#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

struct process {
    pid_t pid;
    int bt, wt, tt; 
    int rt;
    bool finished, started;
};
#define PROCESS struct process

struct round {
    pid_t pid;
    int time;
};
#define ROUND struct round

// assuming maximum number of possible
// rounds be less than 1000
#define MAX_ROUDNS 1000

int main() {
    PROCESS *processes; 
    int iter_index, iter_index2, count, max_counter, cont_index, curr_time;
    unsigned int quantum;
    ROUND *rounds;
    float awt, att;

    printf("How many processes do you want to enter? (integer expected): ");
    scanf("%d", &count);
    // saves from internal fragmentation
    processes = malloc(sizeof(PROCESS) * count);

    printf("Value of time quantum? (unsigned integer expected): ");
    scanf("%u", &quantum);

    // user input of burst time for each process
    for(iter_index = 0; iter_index < count; iter_index++) {
        printf("--- Process %d ---\n", iter_index);
        processes[iter_index].pid = iter_index + 1;

        processes[iter_index].finished = false;

        printf("Burst Time? (integer expected): ");
        scanf("%d", &processes[iter_index].bt);
        processes[iter_index].rt = processes[iter_index].bt;
    }
    puts("");

    rounds = malloc(sizeof(ROUND) * MAX_ROUDNS);
    max_counter = cont_index = 0;
    curr_time = 0;
    while(max_counter < count) {
        for(iter_index = 0; iter_index < count; iter_index++) {
            
            // continue execution for next process
            // when remaining time is 0
            if(processes[iter_index].rt == 0) {
                if(!processes[iter_index].finished) {
                    processes[iter_index].finished = true;
                    max_counter++;
                } 
                continue;
            }
            
            // make an execution round and
            // reduce the remaining time accordingly
            rounds[cont_index].pid = processes[iter_index].pid;
            if(processes[iter_index].rt / quantum == 0) {
                rounds[cont_index].time = processes[iter_index].rt;
            }
            else {
                rounds[cont_index].time = quantum;
            }
            processes[iter_index].rt -= rounds[cont_index].time;
            curr_time += rounds[cont_index].time;
            cont_index++;
        }
    }

    // calculate wait time and turn around time
    // make some clearance, first
    for(iter_index = 0; iter_index < count; iter_index++) {
        processes[iter_index].wt = processes[iter_index].tt = 0;
        processes[iter_index].rt = 0;
        processes[iter_index].finished = processes[iter_index].started = false;
    }
    // calculate 
    curr_time = 0;
    for(iter_index = 0; iter_index < cont_index; iter_index++) {
        for(iter_index2 = 0; iter_index2 < count; iter_index2++) {
            if(rounds[iter_index].pid != processes[iter_index2].pid) continue;

            if(!processes[iter_index2].started) {
                processes[iter_index2].started = true;
                processes[iter_index2].wt = curr_time;
            }

            processes[iter_index2].rt += rounds[iter_index].time;

            if(processes[iter_index2].rt == processes[iter_index2].bt) {
                processes[iter_index2].finished = true;
                processes[iter_index2].tt = curr_time + rounds[iter_index].time;
            }
        }
        curr_time += rounds[iter_index].time;
    }

    // show process statistics
    puts("Round Robin Scheduling");
    printf("---------------------------------\n");
    printf("|PID\t|BT\t|WT\t|TT\t|\n");
    printf("---------------------------------\n");
    for(iter_index = 0; iter_index < count; iter_index++) {
        printf("|%02d\t|%02d\t|%02d\t|%02d\t|\n", processes[iter_index].pid, processes[iter_index].bt, 
            processes[iter_index].wt, processes[iter_index].tt);
    }
    printf("---------------------------------\n");
    puts("");


    // display a Gannt Chart
    printf("Gantt Chart\n");
    for(iter_index = 0; iter_index < cont_index; iter_index++) {
        printf("----");
        for(iter_index2 = 0; iter_index2 < rounds[iter_index].time; iter_index2++) {
            printf("-");
        }
    }
    printf("-\n");

    for(iter_index = 0; iter_index < cont_index; iter_index++) {
        printf("|P%02d", rounds[iter_index].pid);
        for(iter_index2 = 0; iter_index2 < rounds[iter_index].time; iter_index2++) {
            printf(" ");
        }
    }
    printf("|");
    puts("");

    for(iter_index = 0; iter_index < cont_index; iter_index++) {
        printf("----");
        for(iter_index2 = 0; iter_index2 < rounds[iter_index].time; iter_index2++) {
            printf("-");
        }
    }
    printf("-\n");

    curr_time = 0;
    for(iter_index = 0; iter_index < cont_index; iter_index++) {
        printf("%02d  ", curr_time);
        for(iter_index2 = 0; iter_index2 < rounds[iter_index].time; iter_index2++) {
            printf(" ");
        }
        curr_time += rounds[iter_index].time;
    }
    printf("%02d\n", curr_time);

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
