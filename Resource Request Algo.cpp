#include<stdio.h>
void resource_request(int process,int request[],int availabel[],int max[][3],int allocation[][3])
{
	
	int i;
	for(i=0;i<3;++i)
	{
		if(request[i]>availabel[i])
		{
			printf("process can not be granted due to insufficient resourecs ",process);
		}
	}
	for(i=0;i<3;i++)
	{
		availabel[i]-=request[i];
		allocation[process][i]+=request[i];
	}
	printf(" resources request for process %d granted",process);
}

	

int main()
{
	int available[]={ 3,3,2};
	int max[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	int allocation[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,1}};
	int  process=1;
	int request[3]={1,0,2};
	resource_request(process,request,available,max,allocation);
	return 0;
	
	
	
}
