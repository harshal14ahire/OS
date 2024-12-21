#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int n, i, timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (i = 0; i < n; i++)
	{
        processes[i].id = i+1;
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    printf("\nGantt Chart:\n");
    //set time=0
    int time = 0;
    // while(1)
    
    while (1)
	{
        /// set done=1
		int done = 1;
        for (i = 0; i < n; i++)
		{
            if (processes[i].remainingTime > 0)
			 {
                done = 0;
                int executeTime = min(timeQuantum, processes[i].remainingTime);

                printf("| P%d ", processes[i].id);
                time += executeTime;
                processes[i].remainingTime -= executeTime;

                if (processes[i].remainingTime == 0)
				{
                    processes[i].turnaroundTime = time - processes[i].arrivalTime;
                    processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
                }
            }
        }

        if (done == 1)
            break;
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

