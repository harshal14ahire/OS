
#include <stdio.h>
//#include <stdlib.h>
// dfine structure with new brust time
struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;//remaining time
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
            if (processes[j].burstTime > processes[j+1].burstTime)
                swap(&processes[j], &processes[j+1]);
}

int main() {
    int n, i;
// accept no of process

    printf("Enter the number of processes: ");
    scanf("%d", &n);
// declare structure array for n processs

    struct Process processes[n];
		//accept process data
    for (i = 0; i < n; i++) {
        processes[i].id = i+1;
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }
	//ssor process on brust time
    sortProcesses(processes, n);
//print gant chart 
    printf("\nGantt Chart:\n");
    //declare time counter 
    int time = 0;
    while (1)
	 {
        int shortest = -1;
        for (i = 0; i < n; i++)
		 {
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0)
			 {
               if (shortest == -1 || processes[i].remainingTime < processes[shortest].remainingTime)
                    shortest = i;
            }
        }

        if (shortest == -1)
            break;

        printf("| P%d ", processes[shortest].id);
        processes[shortest].remainingTime--;

        time++;

        if (processes[shortest].remainingTime == 0) {
            processes[shortest].turnaroundTime = time - processes[shortest].arrivalTime;
            processes[shortest].waitingTime = processes[shortest].turnaroundTime - processes[shortest].burstTime;
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

