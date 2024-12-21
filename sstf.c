#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 1000

void sort(int arr[], int n) {int i,j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

int find_closest_request(int requests[], int n, int head, int visited[]) {
    int min_distance = __INT_MAX__;
    int index = -1; int i;
    for ( i = 0; i < n; i++) {
        if (!visited[i]) {
            int distance = abs_diff(head, requests[i]);
            if (distance < min_distance) {
                min_distance = distance;
                index = i;
            }
        }
    }
    return index;
}

int main() {
    int n, head, total_head_movements = 0;

    int requests[8] = {98, 183, 41, 122, 14, 124, 65, 67};
    n = sizeof(requests) / sizeof(requests[0]);
    head = 53;

    sort(requests, n);

    printf("Sequence of requests served:\n");
    printf("%d ", head);

    int visited[MAX_REQUESTS] = {0};
int i;
    for (i = 0; i < n; i++) {
        int closest_index = find_closest_request(requests, n, head, visited);
        total_head_movements += abs_diff(head, requests[closest_index]);
        printf(" -> %d ", requests[closest_index]);
        head = requests[closest_index];
        visited[closest_index] = 1; // Mark as visited
    }

    printf("\nTotal number of head movements: %d\n", total_head_movements);

    return 0;
}

