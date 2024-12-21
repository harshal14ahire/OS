#include<stdio.h>
typedef struct job
{
	int pno,btime,atime,wtime,tatime;
}P;
int main()
{
	int n;
	printf(" how many process:");
	Scanf("%d",&n);
	
	P p[10];
	
	for(int i=0;i<n;i++)
	{
		printf(" enter process no|brust time|arrival time");
		scanf("%d %d %d ",&p[i].pno,&p[i].btime,&p[i].atime);
		
	}
	
	
	return 0;
}
