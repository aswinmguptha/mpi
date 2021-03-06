#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	MPI_Init(NULL, NULL);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	int size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if(size != 2){
		printf("Run this job with two processes\n");
		printf("mpirun -n 2 %s\n", argv[0]);
		MPI_Abort(MPI_COMM_WORLD, 1);
	}
	
	int number;

	if(rank == 0){
		printf("Enter a number: ");
		scanf("%d", &number);
		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}
	
	else if(rank ==1){
		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process 1 received number %d from process 0\n", number);
	}
	
	MPI_Finalize();
}
