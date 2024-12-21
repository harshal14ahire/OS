#include<stdio.h>
#include<stdlib.h>

#define MAX_FRAMES 10

int main() { int i,k,j;
    int capacity, frames[MAX_FRAMES], pageFaults = 0;
    int referenceString[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int referenceStringLength = sizeof(referenceString) / sizeof(referenceString[0]);

    printf("Enter the number of memory frames: ");
    scanf("%d", &capacity);

    for ( i = 0; i < capacity; i++)
	 {
        frames[i] = -1;  // Initialize frames to -1 indicating empty
    }

    for ( i = 0; i < referenceStringLength; i++)
	 {
        int page = referenceString[i];
        int pageFound = 0;

        // Check if the page is already in a frame
        for (j = 0; j < capacity; j++) 
		{
            if (frames[j] == page)
			 {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound)
		 {
            int replaceIndex = -1;
            int farthestUse = -1;

            // Find the page to replace based on future references
            for (j = 0; j < capacity; j++)
			 {
                int nextUse = 0;
                for ( k = i + 1; k < referenceStringLength; k++)
				 {
                    if (referenceString[k] == frames[j])
                    
					 {
                        nextUse = k;
                        break;
                    }
                }

                if (nextUse == 0)
				 {
                    replaceIndex = j;
                    break;
                }

                if (nextUse > farthestUse)
				 {
                    farthestUse = nextUse;
                    replaceIndex = j;
                }
            }

            frames[replaceIndex] = page;
            pageFaults++;

            // Print the current state of frames
            printf("Frames: ");
            for (j = 0; j < capacity; j++)
			 {
                printf("%d ", frames[j]);
            }
            printf("   Page Faults: %d\n", pageFaults);
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
