#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* contiguous file allocation 
logic:
1=create Bit vextor array of Max Size
2=write fun init() to intialised to all array to ={1}
3= fun createfile(int firstBlock int end) allocate all block bet start to end block
4)= fun directory () print file name ,starting block and length of file
5) =fun deilete file which frees all blocks
?*/
#define MaxSize 100
int start,end ;
char filename[20];
int BitVector[MaxSize]; 
int fn=0;
typedef struct dir{char filename[20];
int start,length;
}DIR;
DIR Dir[10];
void init()
{
	int i;
	for(i=0;i<MaxSize;i++)
	{
		BitVector[i]=1;
		
		
	}
}
void showBitVector()
{
		int i;
	for(i=0;i<MaxSize;i++)
	{
	printf("%d\n",BitVector[i]);
}
   
	
}
 void CreateFile(int start ,int end,char filename[])
 {  int i;
 	for(i=start;i<end;i++)
 	{
 		BitVector[i]=0;
	 }
	strcmp( Dir[fn].filename,filename);
	 Dir[fn].length=end-start;
	 Dir[fn].start=start;
	 fn++;
	 printf("file created Successfully:%s",filename);
	 
	 
 	
 }
void directory()
{ for(int i=0;i<fn;i++){

	printf("\n%s is Store in Disk..",Dir[i].filename);
	printf("\n%d is starting Block of File Storage Location on Disk .." ,Dir[i].start);
	printf("\n%d is length of file", Dir[i].length);
}
}
void DeleteFile(char fileName[],int satrt,int end)
{ 
  if(strcmp(fileName,filename))
    {  for(int i=start;i<end;i++)
    {
    	BitVector[i]=0;
	}
 	
    }
    
	
}
int main()
{
	init();int ch;
	do{
		
			printf("\n1=Show Bit Vector");
			printf("\n2=Create New File");
			printf("\n3=Show Directory");
			printf("\n4=Delete file");
			printf("\n5=Exit");
			printf("\nEnter Your Choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:showBitVector();
					break;
					
						case 2: 
						printf("Enter File Name:");
						scanf("%s",&filename);
						printf("Eneter Starting Block:");
							scanf("%d",&start);
							printf("Enter Ending Block:");
							scanf("%d",&end);
						CreateFile(start,end,filename);
							
							
					break;
					
						case 3:directory();
					break;
					
					
					
						case 4:
						printf("Enter File to deleter");
					char fn[20];
					DeleteFile(fn,start,end);
					
					break;
						case 5:
					exit(0);
		
					break;
          	}
			}while(ch!=5);
			
return 0;		
	
}


