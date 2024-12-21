#include<stdio.h>
#include<stdlib.h>

typedef struct job
{
	int pno,btime,atime,wtime,tatime;
}P;
 void sort(P p[],int n);
int main()
{
	int n;
	printf(" how many process:");
	scanf("%d",&n);
	
	P p[10];
	int i;
	for(i=0;i<n;i++)
	{
		printf(" enter process no|brust time|arrival time");
		scanf("%d%d%d",&p[i].pno,&p[i].btime,&p[i].atime);
		
	}
	sort(p,n);
	
		for(i=0;i<n;i++)
	{
		
		printf("%d\t%d\t%d",p[i].pno,p[i].btime,p[i].atime);
		
	}
	
	
	
	
	return 0;
}
 void sort(P p[],int n)
 {
 	int i,j; int t1,t2;
 	for(i=1;i<n;i++)
 	{
 		for(j=0;j<n-i;j++)
 		{
 			if (p[j+1].btime < p[j].btime)
 			{
 			//	 t1=p[j+1].btime;
 				 t2=p[j+1].atime;
 				 p[j+1].atime=p[j].atime;
 				 //p[j+1].btime=p[j].btime;
 				 p[j].atime=t2;
 				 //p[j].btime=t1;
 				 
 				
			 }
			 	 t1=p[j+1].btime;
			 	 	 p[j+1].btime=p[j].btime;
			 	 	 	 p[j].btime=t1;
		 }
	 }
 }
