//
#include <stdio.h>
// function of fifo
// take refstrung as page[] array,int n,and  and noof Frames = capacity
void fifo(int pages[], int n, int capacity)
 {
    int frame[capacity];//declare array for n frames[]
    int frameIndex = 0;//set frame index and page fault to zero
    int pageFaults = 0;
		int i,j;
		for(j=0;j<capacity;j++)
		{
			frame[j]=0;
		}
		/// traverse reference string 
    for ( i = 0; i < n; i++) 
      {  int page = pages[i];//pik one page
        int pageFound = 0;// set page found to 0
			// traverse frame array to check page is alrady present 
        // Check if the page is already in memory
        for ( j = 0; j < capacity; j++)
		 {
            if (frame[j] == page)
			 {
            	// if page is found then pageFound =1;
                pageFound = 1;
                break;
               // break loop
            }
        
		}
                                                                                   
        // If page is not in memory, replace the oldest page with the new page
        if (!pageFound)
		 {
            frame[frameIndex] = page;
            frameIndex = (frameIndex + 1) % capacity;
            // if page is not found in Main memmory then increment pageFault
            pageFaults++;
        }

        // Print the page scheduling after each reference
        printf("\nPage Scheduling after reference %d: ", i + 1);
        for ( j = 0; j < capacity; j++)
		 {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }

    // Print total number of page faults
    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int n, capacity;

    // Input: Number of memory frames (capacity)

    printf("Enter the number of memory frames: ");
    scanf("%d", &capacity);                                                      
    
     printf("How many pages in your refstring:");
    
     scanf("%d", &n);
    // Input: Page reference string
    int pages[n];// = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};//16/2//64/4 16
    printf(" enetr ref string:");
    int i;
  
    for(i=0;i<n;i++)
    {
    	scanf("%d",&pages[i]);
    	
	}
	
	//
//	n = no;//,sizeof(pages) / sizeof(pages[0]);
    // printf("\n%d\t %d",sizeof(pages),sizeof(pages[0]));
    // Call FIFO function
    fifo(pages, n, capacity);

    return 0;
}
