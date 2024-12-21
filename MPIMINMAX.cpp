#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <limits.h>
#include <time.h> // Include for time

#define ARRAY_SIZE 1000

int main(int argc, char *argv[]) {
    int rank, size;
    int array[ARRAY_SIZE];
    int local_min = INT_MAX, local_max = INT_MIN;
    int global_min, global_max;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    // Generate random numbers in array
    srand(time(NULL) + rank); // Seed based on current time and rank
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }
    
    // Find local min and max
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] < local_min) {
            local_min = array[i];
        }
        if (array[i] > local_max) {
            local_max = array[i];
        }
    }
    
    // Reduce local mins and maxs to get global min and max
    MPI_Reduce(&local_min, &global_min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_max, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    
    // Print the result from process 0
    if (rank == 0) {
        printf("Global minimum: %d\n", global_min);
        printf("Global maximum: %d\n", global_max);
    }
    
    MPI_Finalize();
    return 0;
}
//mpirun -n <num_processes> ./mpi_program
//mpicc mpi_program.c -o mpi_program===mpicc mpisum.c -o mpisum   // mpirun -np 2 ./mpisum
/*$ mpicc <name of .c file>
Once compilation is successful. Execute the program as follows
$mpitun -np <no. of processors><name of executable file>
$mpirun -np 2 ./a.out*/

