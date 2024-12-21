#include<stdio.h>
#include<mpi.h>
#define Max 1000
int main(int argc,char *argv[])
{
	 int rank,size;
	   int a[Max],local_sum=0,global_sum=0;
	   
	   MPI_Init(&argc,&argv);
	   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	   MPI_Comm_size(MPI_COMM_WORLD,&size);
	   
	   srand(rank);
	   for(int i=0;i<Max;i++)
	   {
	   	a[i]=rand()%100;	//if(a[i]%2==0)
	   	local_sum+=	a[i];	//if(a[i]%2!=0)	
		}
		MPI_Reduce(&local_sum,&global_sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
		if(rank==0)
		{
		  printf("Sum of Numberrs :%d",global_sum);
		}	 
     MPI_Finalize();
	 return 0;
	 	 
}

