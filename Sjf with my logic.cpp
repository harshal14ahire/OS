//create stucture	
#include<stdio.h>
#include<stdlib.h>
typedef struct process {
	int pid;
	int btime;
	int atime;
	int wtime;
	int tatime;
	
} P;
void sortprocessonArrivalTime(P job[],int n)
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

void sortprocessonBrustTime(P job[],int n)
{
	int i,j; P temp;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(job[j].btime>job[j+1].atime)
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
	printf(" how many process:");
	scanf("%d",&n);
	P job[n];int i;
	for(i=0;i<n;i++)
	{
		printf(" Enter|pid|btime|atime");
		scanf("%d%d%d",&job[i].pid,&job[i].btime,&job[i].atime);
		
	}
	
	printf(" \nYour process before Sorting:");
	printf("\npid\tbtime\tatime");
		for(i=0;i<n;i++)
		{
		printf("\n%d\t%d\t%d",job[i].pid,job[i].btime,job[i].atime);
			
		}
		printf("\nort process on brust time");
		sortprocessonBrustTime(job, n);

	for(i=0;i<n;i++)
		{
		printf("\n%d\t%d\t%d",job[i].pid,job[i].btime,job[i].atime);
			
		}
		sortprocessonArrivalTime(job,n);

	printf(" \n sort on arrival:");
	
	 printf("\npid\tbtime\tatime");
		for(i=0;i<n;i++)
		{
		printf("\n%d\t%d\t%d",job[i].pid,job[i].btime,job[i].atime);
			
		}
		
		job[0].wtime=0;
		job[0].tatime=job[0].btime;
		int waitingtime=0;
		int tatime=0;
		printf("\nGant Chart:");
		for(i=0;i<n;i++)
		{
			printf("[P%d]",job[i].pid);
		}
		printf("\npid\twaiting time\ttaround time");
		for(i=1;i<n;i++)
		{
		
			job[i].wtime=job[i-1].wtime+job[i-1].btime;
			job[i].tatime=job[i].wtime+job[i].btime;
			waitingtime+=job[i].wtime;
			tatime+=job[i].tatime;
			}
			
			printf("\npid\tbrust time\t arriaval time\t waiting time\t turn around time\n");
			
			for(i=0;i<n;i++)
			{
			printf("\n%d\t%d\t\t%d\t\t%d\t\t%d\n",job[i].pid,job[i].btime,job[i].atime,job[i].wtime,job[i].tatime);
			}
		printf("\n Average waiting time is:%f" ,(float)(waitingtime)/n);
		printf("\nAverage turn around time is :%f" ,(float)(tatime)/n);
		
		
		
		
		return 0;
		
	}
