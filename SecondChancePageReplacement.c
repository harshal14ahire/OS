#include <stdio.h>

#define MAX_FRAMES 10

int main() {
    int referenceString[] = {2, 5, 2, 8, 5, 4, 1, 2, 3, 2, 6, 1, 2, 5, 9, 8};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int frames[MAX_FRAMES];
    int referenceBit[MAX_FRAMES];
    int pageFaults = 0;
	int i,j;
    printf("Enter the number of memory frames: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        frames[i] = -1; // Initialize frames with -1 indicating an empty frame
        referenceBit[i] = 0; // Initialize reference bits to 0
    }

    int index = 0; // Index for the clock hand

    for ( i = 0; i < n; i++) {
        int page = referenceString[i];
        int pageFound = 0;

        // Check if the page is already in a frame
        for (j = 0; j < n; j++) {
            if (frames[j] == page) {
                referenceBit[j] = 1; // Set reference bit to 1
                pageFound = 1;
                break;
            }
        }

        // If the page is not in a frame, replace a page using the clock algorithm
        if (!pageFound) {
            while (1) {
                if (referenceBit[index] == 0) {
                    // Replace the page at the current clock hand position
                    frames[index] = page;
                    referenceBit[index] = 1; // Set reference bit to 1
                    index = (index + 1) % n; // Move the clock hand
                    break;
                } else {
                    referenceBit[index] = 0; // Reset reference bit to 0
                    index = (index + 1) % n; // Move the clock hand
                }
            }

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
