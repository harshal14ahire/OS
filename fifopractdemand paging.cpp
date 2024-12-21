#include<stdio.h>


void fifo(int pages[],int n,int capacity)
{
	int pagefault=0,frames[capacity],i,j,frameIndex=0;
 for(j=0;j<n;j++)
 {
 	frames[i]=0;
 }
	for(i=0;i<n;i++)
	{
	int page=pages[i];
		int  hit=0;
		for(j=0;j<capacity;j++)
		{
			if(frames[j]==page)
			{
				hit=1;
				break;
			}
		}
		
		if(!hit)
		{
				frames[frameIndex]=page;
				frameIndex=(frameIndex+1)%capacity;
				pagefault++;
			
		}
		printf("pagescheduling afther %d:",i+1);
		for(j=0;j<capacity;j++)
		{ 
		printf("%d\t",frames[j]);
			
		}
		printf("\n");
		
	}
	printf(" no of total page faults are:%d",pagefault);
	
}
int main()
{
	int capacity,n;
	printf(" \nno of frames:");
	scanf("%d",&capacity);
	printf(" \nlength of ref string:");
	scanf("%d",&n);
	int i;
	int pages[n];
	for(i=0;i<n;i++)
	{scanf("%d",&pages[i]);
	
	}
	fifo(pages,n,capacity);
	
	return 0;
}
