#include<stdio.h>
#include<stdlib.h>

struct Process {
    int id;
    int arrival_time;
    int cpu_burst;
    int turnaround_time;
    int waiting_time;
};

void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_by_arrival_time(struct Process processes[], int n) { int i,j;
    for (i = 0; i < n-1; i++)
        for ( j = 0; j < n-i-1; j++)
            if (processes[j].arrival_time > processes[j+1].arrival_time)
                swap(&processes[j], &processes[j+1]);
}

void sjf(struct Process processes[], int n) {
    sort_by_arrival_time(processes, n);
  int i;
    int current_time = 0;

    for ( i = 0; i < n; i++) {
        // Simulate IO waiting time
        current_time += 2;

        processes[i].waiting_time = current_time - processes[i].arrival_time;

        current_time += processes[i].cpu_burst;

        processes[i].turnaround_time = current_time - processes[i].arrival_time;

        printf("P%d | ", processes[i].id);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    int i;
    for (i = 0; i < n; i++) {
        processes[i].id = i+1;
        printf("Enter arrival time for process P%d: ", i+1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter first CPU burst for process P%d: ", i+1);
        scanf("%d", &processes[i].cpu_burst);

        // Generate random next CPU burst time (assuming a range of 1 to 10 units)
        processes[i].cpu_burst += rand() % 10 + 1;
    }

    printf("\nGantt Chart: ");
    sjf(processes, n);

    // Calculate average waiting time and turnaround time
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for ( i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
