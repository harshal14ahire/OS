#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a process
struct Process {
    int pid; // process ID
    int at; // arrival time
    int bt; // burst time
    int ct; // completion time
    int wt; // waiting time
    int tat; // turnaround time
};

// A function to swap two processes
void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

// A function to sort the processes by arrival time
void sort_by_arrival(int n, struct Process proc[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].at > proc[j + 1].at) {
                swap(&proc[j], &proc[j + 1]);
            }
        }
    }
}

// A function to find the shortest job among the arrived processes
int find_shortest_job(int n, struct Process proc[], int curr_time) {
    int min_bt = INT_MAX; // minimum burst time
    int sj_index = -1; // index of the shortest job
    for (int i = 0; i < n; i++) {
        // check if the process has arrived and has burst time less than min_bt
        if (proc[i].at <= curr_time && proc[i].bt < min_bt) {
            min_bt = proc[i].bt;
            sj_index = i;
        }
    }
    return sj_index;
}

// A function to simulate the SJF scheduling algorithm
void sjf_scheduling(int n, struct Process proc[]) {
    // sort the processes by arrival time
    sort_by_arrival(n, proc);

    int curr_time = 0; // current time
    int completed = 0; // number of completed processes
    int total_wt = 0; // total waiting time
    int total_tat = 0; // total turnaround time

    // loop until all processes are completed
    while (completed < n) {
        // find the shortest job among the arrived processes
        int sj_index = find_shortest_job(n, proc, curr_time);
        if (sj_index == -1) {
            // no process has arrived yet, increment the current time
            curr_time++;
        } else {
            // execute the shortest job
            struct Process *sj = &proc[sj_index]; // pointer to the shortest job
            sj->ct = curr_time + sj->bt; // update the completion time
            sj->tat = sj->ct - sj->at; // update the turnaround time
            sj->wt = sj->tat - sj->bt; // update the waiting time
            curr_time = sj->ct; // update the current time
            completed++; // increment the number of completed processes
            total_wt += sj->wt; // update the total waiting time
            total_tat += sj->tat; // update the total turnaround time

            // generate the next CPU burst randomly
            sj->bt = rand() % 10 + 1;
        }
    }

    // print the results
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].at, proc[i].bt, proc[i].ct, proc[i].tat, proc[i].wt);
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);
}

// A function to create and initialize a process
struct Process create_process(int pid, int at, int bt) {
    struct Process p;
    p.pid = pid;
    p.at = at;
    p.bt = bt;
    p.ct = 0;
    p.wt = 0;
    p.tat = 0;
    return p;
}

// Driver code
int main() {int n;
    // create an array of processes
    printf(" how many processs:");
    scanf("%d" ,&n);
    int pid,at,bt,i;
    struct Process proc[n];
    for(i=0;i<n;i++)
    { printf("\n Enrter pid|arrival time |brust Time:");
    scanf("%d",&pid);
    scanf("%d",&at);
    scanf("%d",&bt);
	   // struct Process proc[n];
    proc[i] = create_process(pid, at, bt);
    //proc[1] = create_process(2, 1, 4);
    //proc[2] = create_process(3, 2, 9);
    //proc[3] = create_process(4, 3, 5);
}
    // call the sjf_scheduling function
    sjf_scheduling(n, proc);

    return 0;
}
