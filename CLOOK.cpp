#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order
void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to simulate disk scheduling using C-SCAN algorithm
void c_scan(int requests[], int n, int head, int max_track, int direction)
{
    int total_head_movement = 0;
    int current_track = head;

    //Sort the requests
    sort(requests, n);

    if (direction == 1) 
	{ // Moving towards higher tracks
        // Move towards higher tracks
        for (int i = 0; i < n; i++) 
		{
            if (requests[i]>current_track) 
			{
                total_head_movement += abs(requests[i] - current_track);
                current_track = requests[i];
            }
        }

      
        // Move towards lower tracks
        for (int i = 0; i < n; i++) 
		{
            if (requests[i] < head) 
			{
                total_head_movement += abs(requests[i] - current_track);
                current_track = requests[i];
            }
        }
    }
	else 
	{ // Moving towards lower tracks
        // Move towards lower tracks
        for (int i = n - 1; i >= 0; i--) 
		{
            if (requests[i] <= current_track && requests[i] >= 0) 
			{
                total_head_movement += abs(requests[i] - current_track);
                current_track = requests[i];
            }
        }

        // Move to the last track if not already at the minimum track
       
	 total_head_movement += abs(requests[0] - requests[n-1]);
        // Move towards higher tracks
        current_track=requests[n-1];
        for (int i = n - 1; i >= 0; i--) 
		{
            if (requests[i] <current_track) 
			{
                total_head_movement += abs(requests[i] - current_track);
                current_track = requests[i];
            }
        }
    }
   
    printf("Total number of seek operations = %d\n", total_head_movement);
    printf("Resulting head position = %d\n", current_track);
}

int main() {
    int n;
    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the track positions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    int head, max_track, direction;
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the maximum track number: ");
    scanf("%d", &max_track);
    printf("Enter the direction (0 for towards lower, 1 for towards higher): ");
    scanf("%d", &direction);

    c_scan(requests, n, head, max_track, direction);

    return 0;
}

