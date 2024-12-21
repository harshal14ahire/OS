#include <stdio.h>

#define MAX_FRAMES 10

int main() {
    int referenceString[] = {2, 5, 2, 8, 5, 4, 1, 2, 3, 2, 6, 1, 2, 5, 9, 8};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int i,j;

    printf("Enter the number of memory frames: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        frames[i] = -1; // Initialize frames with -1 indicating an empty frame
    }

    for ( i = 0; i < n; i++) {
        int page = referenceString[i];
        int pageFound = 0;

        // Check if the page is already in a frame
        for (j = 0; j < n; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        // If the page is not in a frame, replace the most recently used page
        if (!pageFound) {
            int mruIndex = n - 1; // Index of the most recently used page

            // Find the most recently used page in the frames
            for ( j = n - 1; j >= 0; j--) {
                if (frames[j] != -1) {
                    mruIndex = j;
                    break;
                }
            }

            // Replace the most recently used page with the current page
            frames[mruIndex] = page;

            // Increment page fault count
            pageFaults++;

            // Display page scheduling
            printf("Page %d -> ", page);
            for (j = 0; j < n; j++) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        }
    }

    printf("Total number of page faults: %d\n", pageFaults);

    return 0;
}
