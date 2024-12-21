#include <stdio.h>

#include <stdlib.h>

#define MAX_PROCESSES 10

#define MAX_RESOURCES 10

int n, m; 

int Allocation[MAX_PROCESSES][MAX_RESOURCES], Max[MAX_PROCESSES][MAX_RESOURCES], Need[MAX_PROCESSES][MAX_RESOURCES];

int Avail[MAX_RESOURCES], Request[MAX_RESOURCES];

int Finish[MAX_PROCESSES], Safe[MAX_PROCESSES];

int work[MAX_RESOURCES];

int proc, pno;

void Display_matrix() 
{ int i,j;
    printf("\n\tAllocation\t\tMax\t\tNeed\n");
    for ( i = 0; i < n; i++)
	 {
        for ( j = 0; j < m; j++)
            printf("%d\t", Allocation[i][j]);
        printf("\t");
        for (j = 0; j < m; j++)
            printf("%d\t", Max[i][j]);
        printf("\t");
        for ( j = 0; j < m; j++)
            printf("%d\t", Need[i][j]);
        printf("\n");
    }
    printf("\nAvailable\n");
    for ( j = 0; j < m; j++)
        printf("%d\t", Avail[j]);
}

void Find_Need()
 { int i,j;
    for ( i = 0; i < n; i++)
        for ( j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];
}

void Accept_Request() 
{
	int i;
    printf("\nEnter process no:");
    scanf("%d", &proc);
    for ( i = 0; i < m; i++)
        scanf("%d", &Request[i]);
}

int compare_need(int p)
 { 
    int i,j;
    int flag = 0;
    for ( j = 0; j < m; j++)
	 {
        if (Need[p][j] > work[j])
		 {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return p;
    return -1;
}

void Safety_algo()
 {
    int over = 0, flag;
    int i, j, k, l = 0;

    for (i = 0; i < m; i++)
        work[i] = Avail[i];

    while (!over) 
	{
        for (i = 0; i < n; i++)
		 {
            if (Finish[i] == 0)
			 {
                flag = 0;
                pno = compare_need(i);
                if (pno > -1)
                    break;
            }
        }

        if (i == n) 
		{
            printf("System is unsafe\n");
            exit(1);
        }

        if (i < n && pno >= 0) 
		{
            for (k = 0; k < m; k++)
                work[k] += Allocation[pno][k];

            Finish[pno] = 1;
            Safe[l++] = pno;

            if (l >= n) 
			{
                printf("\nSafe sequence is: ");
                for (l = 0; l < n; l++)
                    printf("P%d\t", Safe[l]);
                over = 1;
            }
        }
    }
}

void Resource_request_algo()
 { int i,j;
    for ( i = 0; i < m; i++)
	 {
        if (Request[i] > Need[proc][i])
		 {
            printf("Error: Process exceeds its Max demand\n");
            exit(1);
        }
    }

    for ( i = 0; i < m; i++)
	 {
        if (Request[i] > Avail[i]) {
            printf("Process must wait, resources not available\n");
            exit(1);
        }
    }

    for ( i = 0; i < m; i++)
	 {
        Avail[i] -= Request[i];
        Allocation[proc][i] += Request[i];
        Need[proc][i] -= Request[i];
    }

    Safety_algo();
}

void Bankers_algo()
 {
    Resource_request_algo();
}

int main() {
	int i,j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the Allocation matrix:\n");
    for ( i = 0; i < n; i++)
        for ( j = 0; j < m; j++)
            scanf("%d", &Allocation[i][j]);

    printf("Enter the Max matrix:\n");
    for (i = 0; i < n; i++)
        for ( j = 0; j < m; j++)
            scanf("%d", &Max[i][j]);

    printf("Enter the Available matrix:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &Avail[i]);

    Display_matrix();
    Find_Need();
    Bankers_algo();

    return 0;
}
