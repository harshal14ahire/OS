#include <stdio.h>
#include <stdlib.h>
//create structue variable
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
// sort on priority
void sortProcesses(struct Process processes[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)//5>4 low first// hight 4<5
        for (j = 0; j < n-i-1; j++)
            if (processes[j].priority > processes[j+1].priority)
                swap(&processes[j], &processes[j+1]);
}
// sort on brust time 



int main() {
    int n, i;
    // read n/

    printf("Enter the number of processes: ");
    scanf("%d", &n);
 printf("\n----------------------------------------------------------\nNote that lowest priority Number has Highest priority: \n");
    struct Process processes[n];
printf("\n----------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        processes[i].id = i+1;
        printf("Enter arrival time, burst time, and priority for process %d: ", i+1);
        scanf("%d %d %d", &processes[i].arrivalTime, &processes[i].burstTime, &processes[i].priority);// read process Data
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    sortProcesses(processes, n);// first sort on priority
	sortProcessesonBrust(processes, n);// sort on brust time
    printf("\nGantt Chart:\n");
    //print gant chart 
    // assingn time=0
    int time = 0;
    for (i = 0; i < n; i++) {// pass process data
       
// print gant chart
        printf("| P%d ", processes[i].id);
        // update time every time with ith proceess
        time += processes[i].burstTime;
		//tat[i]=time-atime[i]
		// wt[i]=tat[i]-btime[i];
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

