#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv){
	MPI_Init(NULL, NULL);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if(size < 2){
		printf("Run this job with atleast two processes\n");
	        printf("mpirun -n 2 %s\n", argv[0]);
	        MPI_Abort(MPI_COMM_WORLD, 1);
	}

	int number;

	if(rank == 0){
		printf("Enter a number: ");
	        scanf("%d", &number);
	        MPI_Send(&number, size, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}

	MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);

	printf("Process %d received number %d from process 0\n", rank, number);
	MPI_Finalize();
	
}
