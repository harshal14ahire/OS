#include <stdio.h>

#define MAX_FRAMES 10

typedef struct
 {
    int page;
    int counter;
 } PageEntry;

int main() {
    int referenceString[] = {2, 5, 2, 8, 5, 4, 1, 2, 3, 2, 6, 1, 2, 5, 9, 8};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int frames[MAX_FRAMES];
    PageEntry pageTable[MAX_FRAMES];
    int pageFaults = 0;
    int i,j;
    

    printf("Enter the number of memory frames: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        frames[i] = -1; // Initialize frames with -1 indicating an empty frame
        pageTable[i].page = -1; // Initialize page table with -1 indicating an empty entry
        pageTable[i].counter = 0; // Initialize counters to 0
    }

    for ( i = 0; i < n; i++)
	 {
        int page = referenceString[i];
        int pageFound = 0;

        // Check if the page is already in a frame
        for ( j = 0; j < n; j++)
		 {
            if (frames[j] == page) {
                pageTable[j].counter++; // Increment the counter
                pageFound = 1;
                break;
            }
         }

        // If the page is not in a frame, replace the least frequently used page
        if (!pageFound) {
            int minCounterIndex = 0;

            // Find the page with the minimum counter value
            for ( j = 1; j < n; j++) {
                if (pageTable[j].counter < pageTable[minCounterIndex].counter) {
                    minCounterIndex = j;
                }
            }

            // Replace the least frequently used page with the current page
            frames[minCounterIndex] = page;
            pageTable[minCounterIndex].page = page;
            pageTable[minCounterIndex].counter = 1; // Reset counter to 1

            // Increment page fault count
            pageFaults++;

            // Display page scheduling
            printf("Page %d -> ", page);
            for ( j = 0; j < n; j++) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        }
    }

    printf("Total number of page faults: %d\n", pageFaults);

    return 0;
}
