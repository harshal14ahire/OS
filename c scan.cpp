#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
 {
    for (int i = 0; i < n - 1; i++)
	 {
        for (int j = 0; j < n - i - 1; j++) 
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
    int n, head,total_head_movements = 0;

    printf("Enter the total number of disk blocks: ");
    scanf("%d", &n);
    

    int requests[n];
  	int i;
  	// accept requested block
    printf("Enter the disk request string: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
	// enter starting block to start head movement
    printf("Enter the current head position: ");
    scanf("%d", &head);
	// print first block
	
    printf("Sequence of requests served:\n");
    printf("%d ", head);
    int fixhead=head;
  // head -block[i] i...n;
  sort(requests,n);
    for ( i = 0; i < n; i++) {
    	if(requests[i]>fixhead){
		
        total_head_movements += abs( requests[i]-head);
         printf("(%d-%d|)>",  requests[i],head);
        head = requests[i];
       }
    }
      
        head = 199;
        total_head_movements+=abs(head-requests[n-1]);
        printf("(%d-%d)>", head,requests[n-1]);
        total_head_movements+=abs(0-199);
         printf("(%d-0)>", head);
         head=0;
    	 for ( i = 0; i < n; i++) {
    	if(requests[i]<fixhead){
		
        total_head_movements += abs( requests[i]-head);
          printf("(%d-%d)>",requests[i],head);
        head = requests[i];
        }
    }
	
    printf("\nTotal number of head movements: %d\n", total_head_movements);

    return 0;
}

