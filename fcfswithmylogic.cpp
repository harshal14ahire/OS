//FCFS allgorithm
	
#include<stdio.h>
#include<stdlib.h>
//create structure variable
typedef struct process {
	int pid;
	int btime;
	int atime;
	int wtime;
	int tatime;
	
} P;
//sort process on arrival time
void sortprocessonarrivaltime(P job[],int n)
{
	int i,j; P temp;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(job[j].atime>job[j+1].atime)
			{
				temp=job[j];
				job[j]=job[j+1];
				job[j+1]=temp;
				
			}
		}
	}
}

int main()
{
	int n ;
	
	//read n;
	printf(" how many process:");
	scanf("%d",&n);
	//declare structur variable
	
	P job[n];int i;
	// read pid,brust time,arrival time
	
	for(i=0;i<n;i++)
	{
		printf(" Enter|pid|btime|atime");
		scanf("%d%d%d",&job[i].pid,&job[i].btime,&job[i].atime);
		
	}
	// print n process afther sorting 
	printf(" \nYour process before Sorting:");
	printf("\npid\tbtime\tatime");
		for(i=0;i<n;i++)
		{
		printf("\n%d\t%d\t%d",job[i].pid,job[i].btime,job[i].atime);
		job[i].wtime=0;
		job[i].tatime=0;
		
			
		}
		
	sortprocessonarrivaltime(job,n);
	printf(" \nYour process afther Sorting:");
	
	 printf("\npid\tbtime\tatime");
		for(i=0;i<n;i++)
		{
		printf("\n%d\t%d\t%d",job[i].pid,job[i].btime,job[i].atime);
			
		}
		// assingn waiting time of first process=0;
		
		job[0].wtime=0;
		// assingn turn around time of first process=brust time of first process
		job[0].tatime=job[0].btime;
		// create variable for assing waiting time,and tur around time
		
		int waitingtime=0;
		int tatime=0;
		//print Gant chart
		
		printf("\nGant Chart:");
		for(i=0;i<n;i++)
		{
			printf("[P%d]",job[i].pid);
		}
		// calculate waiting time
		// waiting [i]=waiting[i-1]+brust[i-1]
		// calculate turn around time
		// turn around[i]=waiting[i]+brust[i];
		
		printf("\npid\twaiting time\ttaround time");
		for(i=1;i<n;i++)
		{
		
			job[i].wtime=job[i-1].wtime+job[i-1].btime;
			job[i].tatime=job[i].wtime+job[i].btime;
			waitingtime+=job[i].wtime;// add All waiting time to total waiting time
			// add all turn around time to total turn around time
			tatime+=job[i].tatime;
			}
			
			printf("\npid\tbrust time\t arriaval time\t waiting time\t turn around time\n");
			//print All process Data
			
			for(i=0;i<n;i++)
			{
			printf("\n%d\t%d\t\t%d\t\t%d\t\t%d\n",job[i].pid,job[i].btime,job[i].atime,job[i].wtime,job[i].tatime);
			}
			//print avrage waiting and avrager turn around time
		printf("\n Average waiting time is:%f" ,((float)(waitingtime)/n));
		printf("\nAverage turn around time is :%f" ,((float)(tatime)/n));
		
		
		
		
		return 0;
		
	}
