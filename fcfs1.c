#include <stdio.h>
#include <stdlib.h>
//create structure for process 
struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};
// implement swaping function using pointer 
void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortProcessesByArrivalTime(struct Process processes[], int n) {
	int i,j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
int i;
    struct Process processes[n];
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int current_time = 0;

    printf("Enter the process details (PID, Arrival Time, Burst Time):\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time);
    }

    // Sort processes by arrival time
    sortProcessesByArrivalTime(processes, n);

    printf("Gantt Chart:\n");
    for (i = 0; i < n; i++) {
        printf("P%d ", processes[i].pid);

        // Calculate waiting time for the current process
     // formula for waiting time [i]=current-arrivaltime[i];
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        // chec if any process have waiting time -ve tehn assign =0
        if (processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0;
        }
         // calculate total waiting time 
         
        total_waiting_time += processes[i].waiting_time;
       // currenttime=currenttime+procceassBrustTime;
       
	    current_time += processes[i].burst_time;

        // Calculate turnaround time for the current process
        // turaroundTime=currentTime-arrival Time 
        processes[i].turnaround_time = current_time - processes[i].arrival_time;
        // calculate Total turn arroud time;
        
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\n");

    // Print waiting and turnaround times for each process
    printf("Process\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\n", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
    }

    // Calculate and print average turnaround time and average waiting time
    float avg_turnaround_time = (float)total_turnaround_time / n;
    float avg_waiting_time = (float)total_waiting_time / n;

    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);

    return 0;
}
