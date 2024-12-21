#include<stdio.h>
#define MAX 10
int allocation[MAX][MAX];
int maximum[MAX][MAX];//definne max,allocation,available,need,sqq,finish
int need[MAX][MAX];
int available[MAX];
int work[MAX];
int seq[MAX];
int finish[MAX];
  
 void accept(int n,int r)
 {
	int i,j;
	printf("enter the allocation matrix :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
		scanf("%d",&allocation[i][j]);
		}
	}
	printf("enter maximum requirment matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
		  scanf("%d",&maximum[i][j]);
		  need[i][j]=maximum[i][j]-allocation[i][j];
		}
	}
	printf("enter available resourse :\n");
	for(i=0;i<r;i++)
	{
	scanf("%d",&available[i]);
	}

}

	void display(int n,int r)
	{
	int i,j;
	printf("allocation matrix:\n");
	   for(i=0;i<n;i++)
	     {
		   for(j=0;j<r;j++)
		    {
		       printf("%d\t",allocation[i][j]);
		     }
	      printf("\n");
    	}
	printf(" maximum requirment matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
		printf("%d\t",maximum[i][j]);
		}
          printf("\n");
	}
	printf(" \nneed matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
		printf("%d\t",need[i][j]);
		}
          printf("\n");
	}
	
	printf(" available resours:\n");
	for(i=0;i<r;i++)
	
	printf("%d\t",available[i]);
	
	}
	
 	int safeState(int n,int r)
		{
	    	   	    int i,j;// declare i,j
	    			int index=0,flag=1,cnt;// declare index=0,flag=1,cnt;
		
					for(i=0;i<n;i++)
					work[i]=available[i];// initialised work=available
					for(i=0;i<n;i++)/// set set flag to All process not finish finish[i]=0
					finish[i]=0;
					for(i=0;i<n;i++)
					{
						for(j=0;j<r;j++)
						{
					
							if(need[i][j]<0)// 
								return 0;// return 0;
					    }
					
				   }
				   
			while (flag)
			{
						flag=0;
								 for(i=0;i<n;i++)// traverse process
 									{
											cnt=0;
											if(finish[i]==0)// cheak process is finish or not 
											{
	    			   							   for(j=0;j<r;j++)// traverse to cloumns
	   				  							   {
	    												 if(need[i][j]<=work[j])// chck need is < work
	        		    									 cnt++;// then cnt++
	     				 									else
            													break;// else stop break
        			    						    } 
	   												if(cnt==r)// if cnt==r if All process have same or resources
    												{ 
													for(j=0;j<r;j++)
	      										    work[j]=work[j]+allocation[i][j];
	      											seq[index]=i;
	       											 index++;
	      											 finish[i]=1;
	       											 flag=1;
	   												}	 
											}
  									}	
			}
				for(i=0;i<n;i++)
					if(finish[i]==0)
					return 0;
		return 1;
}
int main()
	{
	int n,r,i;
	int result;
		printf("how many process:");
		scanf("%d",&n);
	printf("how many resourse:");
		scanf("%d",&r);
	accept(n,r);
	display(n,r);
 	result=safeState(n,r);
				if(result==0)
					{
						printf("\n not in safe state.......!");
				    }
			else
			{
				printf("\n safe sequence state:");
				for(i=0;i<n;i++)
				printf("P%d\t",seq[i]);
			}
		return 0;
}

