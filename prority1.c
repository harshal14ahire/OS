#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortProcesses(struct Process processes[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (processes[j].priority > processes[j+1].priority)
                swap(&processes[j], &processes[j+1]);
}

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (i = 0; i < n; i++) {
        processes[i].id = i+1;
        printf("Enter arrival time, burst time, and priority for process %d: ", i+1);
        scanf("%d %d %d", &processes[i].arrivalTime, &processes[i].burstTime, &processes[i].priority);
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    sortProcesses(processes, n);

    printf("\nGantt Chart:\n");
    int time = 0;
    for (i = 0; i < n; i++) {
        while (time < processes[i].arrivalTime) {
            printf("| Idle ");
            time++;
        }

        printf("| P%d ", processes[i].id);
        time += processes[i].burstTime;

        processes[i].turnaroundTime = time - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
    printf("|\n");

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    float avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i].id, processes[i].turnaroundTime, processes[i].waitingTime);
        avgTurnaroundTime += processes[i].turnaroundTime;
        avgWaitingTime += processes[i].waitingTime;
    }

    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime/n);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime/n);

    return 0;
}

