#include <stdio.h>
#include <stdlib.h>

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
  // head -block[i] i...n;
  
    for ( i = 0; i < n; i++) {
    	
        total_head_movements += abs( requests[i]-head);
        head = requests[i];
        printf("%d--:>", head);
    }

    printf("\nTotal number of head movements: %d\n", total_head_movements);

    return 0;
}

