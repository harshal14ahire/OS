#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 1000
//first sort request in accesinding order 
void sort(int arr[], int n)
 {
    for (int i = 1; i < n ; i++)
	 {
        for (int j = 0; j < n - i ; j++)
		 {
            if (arr[j] > arr[j + 1]) 
			{
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int find_closest_request(int requests[], int n, int head) 
{	// initaised first minimum distance var =min(head,request[0])
    int min_distance = abs(head-requests[0]);//[53-14 =39    // set index at 0th postion 
    int index = 0;
    // check distance min_dis[0]  from head to request[i(1)+1]
    for (int i = 1; i < n; i++)
	 {  // chek find distance[i] to head compare with min distance
        int distance = abs(head-requests[i]);
        if (distance < min_distance)
		{
            min_distance = distance;
            index = i;
        }
    }
    
    return index;
}

int main()
 {
    int n, head, total_head_movements = 0;

    ///printf("Enter the total number of disk blocks: ");
    //scanf("%d", &n);

    //int requests[MAX_REQUESTS];

   // printf("Enter the disk request string: ");
   // for (int i = 0; i < n; i++) {
     //   scanf("%d", &requests[i]);
    //}
int requests[8] = {98, 183, 41, 122, 14, 124, 65, 67};
    n = sizeof(requests) / sizeof(requests[0]);

    // Starting head position
    head = 53;
   // printf("Enter the starting head position: ");
    //scanf("%d", &head);

    // Sort requests
   //sort(requests, n);// [14 41 65 67 98 122 124 183]
for (int i = 0; i < n; i++)
printf("%d " ,requests[i]);

    printf("Sequence of requests served:\n");
    printf("%d ", head);

    for (int i = 0; i < n; i++)
	 { // find closest index 
        int closest_index = find_closest_request(requests, n, head);
        // calculate head movement =head- request[closest index)
        total_head_movements += abs(head-requests[closest_index]);
        //printf("( %d - %d)",head, requests[closest_index]);
        // move head to  requests[closest indext]
        head = requests[closest_index];
        // print current head position
      //  printf("%d ", head);
        // mark  visted request
        requests[closest_index] = -1; // Mark as visited
    }

    printf("\nTotal number of head movements: %d\n", total_head_movements);

    return 0;
}

