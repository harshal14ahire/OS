#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ARRAY_SIZE 1000

int main(int argc, char *argv[]) {
    int rank, size;
    int array[ARRAY_SIZE];
    int local_sum = 0, global_sum = 0;
    double average = 0.0, global_average = 0.0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Generate random numbers in array
    srand(rank); // Seed for random number generation
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100; // Generate random numbers between 0 and 99
    }

    // Calculate local sum
    for (int i = 0; i < ARRAY_SIZE; i++) {
        local_sum += array[i];
    }

    // Reduce local sums to get global sum
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Calculate global average
    average = (double)global_sum / (double)(ARRAY_SIZE * size);
    MPI_Reduce(&average, &global_average, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print the result from process 0
    if (rank == 0) {
        printf("Global sum: %d\n", global_sum);
        printf("Global average: %f\n", global_average);
    }

    MPI_Finalize();
    return 0;
}

