#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// head-->199--->headforwa-->leess than 0
void sort(int arr[], int n)
 {
    for (int i = 0; i < n-1; i++)
	 {
        for (int j = 0; j < n-i-1; j++) 
		{
            if (arr[j] > arr[j+1])
			 {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, head, direction;
    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the track positions:");
    for (int i = 0; i < n; i++)
	{
	scanf("%d", &arr[i]);
    }
        sort(arr,n);
  for (int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the direction (0 for towards lower, 1 for towards higher): ");
    scanf("%d", &direction);

    int total_head_movement = 0;
    int current_track = head;

    if (direction == 0) 
	{ // Towards lower tracks
        for (int i = 0; i < n; i++)// traverzse in forward direction
		 {
            if (arr[i] <= current_track)
			 {
                total_head_movement += abs(arr[i] - current_track);
                current_track = arr[i];
                 printf("%d-->",current_track);
             }
        }

        total_head_movement += abs(current_track - 0);//also calculate for 0 end of disk
        current_track = 0;// set crrent track to 0;
		 printf("%d-->",current_track);
        for (int i = 0; i <n; i++)//// travewrse in reverse directio
		 {
            if (arr[i] >= current_track) 
			{
                total_head_movement += abs(arr[i] - current_track);
                current_track = arr[i];
                printf("%d-->",current_track);
            }
        }
        
    } 
	else 
	{ // Towards higher tracks//98 183 41 122 14 124 65 67
	
        for (int i = 0; i < n; i++)// traverse in reverse directio 
		 {
            if (arr[i] >= current_track) 
			{
                total_head_movement += abs(arr[i] - current_track);
                current_track = arr[i];
                 printf("%d-->",current_track);
            }
         }

        total_head_movement += abs(current_track - (199));//set head to end of track
        current_track = 199;// set current track 199
		 printf("%d-->",current_track);
        for (int i = n-1; i >=0 ; i--)
		 {
            if (arr[i] <=head) 
			{
                total_head_movement += abs(arr[i] - current_track);
                current_track = arr[i];
                 printf("%d-->",current_track);
            }
        }
    }

    printf("Total number of seek operations = %d\n", total_head_movement);
    printf("Resulting head position = %d\n", current_track);

    return 0;
}
