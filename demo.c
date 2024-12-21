#include<stdio.h>
int main()
{
        int a[]={1,23,45,5,3,2,1,23,43,5,65,45};
        int i,j,k,n=12;
        for(i=0;i<n;i++)
        {	
           for(j=i+1;j<n;)
           {
           	if (a[i]==a[j])
           	{
           		for (k=j;k<11;k++)
           		{ a[k]=a[k+1];
				   }
				  
			   }
			    (n)--;
		   
		   n 
		   else{
		   	j++;
		   }
		   
		   }
        	
		}


	return 0;
}
