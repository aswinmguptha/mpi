#include<mpi.h>
#include<stdio.h>

void main(int argc,char** argv) {
        int rank,size;
        int i,j,temp = 0;
        float ans = 0.0;

        MPI_Init(&argc,&argv);
        MPI_Status status;
        
        MPI_Comm_rank(MPI_COMM_WORLD,&rank);
        MPI_Comm_size(MPI_COMM_WORLD,&size);

        int l[size][size],b[size];
        float x[size];

        for(i = 0; i < size; i++){
                	for(j = 0; j <= i; j++){
                   		 scanf("%d", &l[i][j]);
                	}
                	scanf("%d", &b[i]);
        	}

        if(rank == 0){
                x[rank] = (float)b[rank] / l[rank][rank];
		printf("x[%d] = %f ", rank, x[rank]);
		MPI_Send(&x[0],1, MPI_FLOAT, 1, 1, MPI_COMM_WORLD);
		
        }

	else if(rank < size-1){
                ans = 0.0;
                for(i = 0; i < rank; i++){
			MPI_Recv(&x[i], 1, MPI_FLOAT, rank - 1, 1, MPI_COMM_WORLD, &status);
			printf("x[%d] = %f ", i, x[i]);
			MPI_Send(&x[i], 1, MPI_FLOAT, rank + 1, 1, MPI_COMM_WORLD);
                }
		for(i = 0; i < rank; i++){
			ans += l[rank][i] * x[i];
		}
                x[rank] = (float)(b[rank]-ans) / l[rank][rank];
		printf("x[%d] = %f ", rank, x[rank]);
		MPI_Send(&x[rank], 1, MPI_FLOAT, rank + 1, 1, MPI_COMM_WORLD);
        }

        else {
		for(i = 0; i < rank; i++){
			MPI_Recv(&x[i], 1, MPI_FLOAT, rank - 1, 1, MPI_COMM_WORLD,&status);
		}
		for(i = 0; i < rank; i++){
			ans += l[rank][i] * x[i];
		}
                x[rank] = (float)(b[rank]-ans) / l[rank][rank];
		printf("x[%d] = %f ", rank, x[rank]);
	}
        
        MPI_Finalize();
}

