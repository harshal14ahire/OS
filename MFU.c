#include <stdio.h>
#define MAX_PAGES 100

void mfu(int pages[], int n, int capacity) 
{
    int pagefault = 0, frames[capacity], frequency[capacity], i, j, k, found;

    for (i = 0; i < capacity; i++) {
        frames[i] = -1; // Initialize frames to -1 indicating empty
        frequency[i] = 0; // Initialize frequencies to 0
    }

    for (i = 0; i < n; i++) {
        int page = pages[i];
        found = 0;

        for (j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                frequency[j]++;
                found = 1;
                break;
            }
        }

        if (!found)
		 {
            int mfuIndex = 0;
            for (k = 1; k < capacity; k++)
			 {
                if (frequency[k] > frequency[mfuIndex])
				 {
                    mfuIndex = k;
                }
            }

            frames[mfuIndex] = page;
            frequency[mfuIndex] = 1;
            pagefault++;
        }

        // Print the current state of frames after processing each page
        printf("Page %d: ", page);
        for (j = 0; j < capacity; j++) 
           {
                printf("%d ", frames[j]);
            }
        
        printf("\n");
}

    printf("Total page faults: %d\n", pagefault);
}

int main() {
    int capacity,i, n;

    printf("Number of frames: ");
    scanf("%d", &capacity);

    printf("Length of reference string: ");
    scanf("%d", &n);

    int pages[MAX_PAGES];

    printf("Enter the reference string: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    mfu(pages, n, capacity);

    return 0;
}
