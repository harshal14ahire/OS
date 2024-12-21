/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// non premptive priority scheduling...
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

// Function to compare processes based on priority
int comparePriority(const void *a, const void *b) {
    return ((struct Process *)a)->priority - ((struct Process *)b)->priority;
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    // Sort processes based on priority
    qsort(processes, n, sizeof(struct Process), comparePriority);

    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;

    printf("\nProcess Execution Order:\n");
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrival_time) {
            currentTime = processes[i].arrival_time;
        }

        processes[i].waiting_time = currentTime - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        totalWaitingTime += processes[i].waiting_time;
        totalTurnaroundTime += processes[i].turnaround_time;

        currentTime += processes[i].burst_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].priority,
               processes[i].waiting_time, processes[i].turnaround_time);
    }

    double avgWaitingTime = (double)totalWaitingTime / n;
    double avgTurnaroundTime = (double)totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2lf\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnaroundTime);

    return 0;
}



