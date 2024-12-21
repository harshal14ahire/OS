#include<stdio.h>
int main()
{
	int *p;
	int a=10;
	p=&a;
	int **s=&p;
	printf("\n%p",p);
		printf("\n%p",s);
	
	return 0;
}
