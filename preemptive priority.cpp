#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;
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
	 printf("\n----------------------------------------------------------\nNote that lowest priority Number has Highest priority: \n");
    struct Process processes[n];

    for (i = 0; i < n; i++) {
        processes[i].id = i+1;
        printf("Enter arrival time, burst time, and priority for process %d: ", i+1);
        scanf("%d %d %d", &processes[i].arrivalTime, &processes[i].burstTime, &processes[i].priority);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    printf("\nGantt Chart:\n");
    int time = 0;
    //
    
    
    while (1)
	{
        int highestPriority = -1;
        for (i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0) {
                if (highestPriority == -1 || processes[i].priority < processes[highestPriority].priority)
                    highestPriority = i;
            }
        }

        if (highestPriority == -1)
            break;

        printf("| P%d ", processes[highestPriority].id);
        processes[highestPriority].remainingTime--;

        time++;

        if (processes[highestPriority].remainingTime == 0) {
            processes[highestPriority].turnaroundTime = time - processes[highestPriority].arrivalTime;
            processes[highestPriority].waitingTime = processes[highestPriority].turnaroundTime - processes[highestPriority].burstTime;
        }
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

