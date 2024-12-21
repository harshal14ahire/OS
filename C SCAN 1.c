#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 1000

void sort(int arr[], int n) 
{  int i,j;
    for ( i = 0; i < n - 1; i++) 
	{
        for ( j = 0; j < n - i - 1; j++)
		 {
            if (arr[j] > arr[j + 1]) 
			{
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int requests[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 53;
    int total_head_movements = 0;

    // Sort requests
    sort(requests, n);

    // Move towards larger cylinder numbers
    int i = 0;
    while (i < n && requests[i] > head) 
	{
        i++;
    }
    for (; i < n; i++) 
	{
        total_head_movements += requests[i] - head;
        head = requests[i];
    }

    // Move to cylinder 199
    total_head_movements += 199 - head;
    head = 199;

    // Move towards cylinder 0
    total_head_movements += head;
    head = 0;

    // Move towards remaining requests
    for (i = 0; i < n; i++) 
	{
        total_head_movements += requests[i] - head;
        head = requests[i];
    }

    printf("Total head movements incurred while servicing these requests: %d\n", total_head_movements);

    return 0;
}

