#include<stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 100
//logic select that page that are not used for longest amount of time


int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

void pageFaultsLRU(int pages[], int n, int capacity)
 {
	//declare two array one for frames and one for counters
	
    int frames[capacity];
	int counter[MAX_FRAMES];
    int i, j, page, faults = 0, time = 0;

    for (i = 0; i < capacity; ++i)
	 {
        frames[i]=0;
        counter[i] = 0; // Initialize counters to 0
     }

    for (i = 0; i < n; ++i)
	{
       	 page = pages[i];

        // Check if page is present in frames
       	 int hit = 0;
       	 for (j = 0; j < capacity; ++j)
	    {
            if (frames[j] == page)
			 {
			 	// add onr counter=++time; 
                counter[j] = ++time;
                hit = 1;
                break;
             }
        }

        // If page is not present, find LRU page to replace
        if (!hit)
		 {   //1,
            int pos = findLRU(counter, capacity);
            frames[pos] = page;
            counter[pos] = ++time;
            ++faults;
        }

        // Display current state of frames
        printf("Frames: ");
        for (j = 0; j < capacity; ++j)
		 {
            printf("%d ", frames[j]);
         }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
}

int main() {
    int n, capacity;
    printf("Enter the number of memory frames: ");
    scanf("%d", &capacity);

    printf("Enter the number of elements in the reference string: ");
    scanf("%d", &n);

    int pages[n];int i;
    printf("Enter the reference string: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }

    pageFaultsLRU(pages, n, capacity);

    return 0;
}
