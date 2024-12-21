#include <stdio.h>

void safety_algorithm(int processes, int available[], int max[][3], int allocation[][3]) {
    int work[3];
    int finish[5] = {0};

    // Initialize work with available resources
    for (int i = 0; i < 3; ++i)
        work[i] = available[i];

    int safe_sequence[5];
    int count = 0;

    while (count < processes) {
        int found = 0;
        for (int i = 0; i < processes; ++i) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < 3; ++j) {
                    if (max[i][j] - allocation[i][j] > work[j])
                        break;
                }

                if (j == 3) {
                    for (int k = 0; k < 3; ++k)
                        work[k] += allocation[i][k];

                    safe_sequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("The system is not in a safe state.\n");
            return;
        }
    }

    printf("Safe sequence: ");
    for (int i = 0; i < processes; ++i)
        printf("%d ", safe_sequence[i]);

    printf("\nThe system is in a safe state.\n");
}

int main() {
    // Initialize available, max, and allocation matrices

    int available[3] = {3, 3, 2};
    int max[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int allocation[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};

    int processes = 5;

    safety_algorithm(processes, available, max, allocation);

    return 0;
}

