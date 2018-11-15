#include<mpi.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define SIZE 20

int minpos(int array[], int size){
   int i, minpos = 0;

   for (i=0; i<size; i++)
      minpos = array[i] > array[minpos] ? i: minpos;
   return minpos;
}
void sort(int array[],int  size){
   int i, minpos;
   int temp;

   for(i= size; i > 1; i--) 
   {
      minpos = minpos(array, i);
      temp = array[minpos];
      array[minpos] = array[i-1];
      array[i-1] = temp;
   }
}

void main(int argc,char** argv){
	int rank,size;
    	MPI_Init(&argc,&argv);
    	MPI_Status status;
    	int i,j,temp=0;
    	float ans=0.0;
    	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int arr[SIZE];
	int receive;
	if(rank==0){
		for(i=0;i<SIZE;i++) {
			arr[i]=rand()%SIZE;
			
		}
		int min = arr[0];
	        int max = arr[0];
	       	for(i=0; i < SIZE; i++) {

	                if(arr[i] < min) { min = arr[i]; }

	                if(arr[i] > max) { max = arr[i]; }

	       }
		int element[size];
		for(int d=1; d < size; d++) {
	                element[d] = 0;
	        }
		for(int d=0; d < SIZE; d++) {
	                int inc = max/(size-1);
	                int itr = 1;
	                bool flag2 = false;
	                for(j = inc; j <= max; j = j + inc) {
	                    if(arr[d] <= j) {
	                        element[itr]++;
	                        flag2 = true;
	                        break;
	                    }
	                    itr++;
	                }
	                if (!flag2) {
	                    element[itr-1]++;
	                }
	       }
		for(int i=1; i<size; i++) {
	                MPI_Send(&element[i], 1, MPI_INT, i, 2, MPI_COMM_WORLD);
	            }
		for(int d=0; d < SIZE; d++) {
	                int inc = max/(size-1);
	                int itr = 1;
	                bool flag = false;
	                for ( j = inc; j <= max; j = j + inc) {
	                    if(arr[d] <= j) {
	                        MPI_Send(&arr[d], 1, MPI_INT, itr, 4, MPI_COMM_WORLD);
	                        flag = true;
	                        break;
	                    }
	                    itr++;
	                }
	                if (!flag) {
	                    MPI_Send(&arr[d], 1, MPI_INT, itr-1, 4, MPI_COMM_WORLD);
	                }
	            }
		int lastIndex = 0; int ind = 0;
	            for(i=1; i < size; i++) {
	                int recvArray[element[i]];
	                MPI_Recv(&recvArray[0], element[i], MPI_INT, i, 5, MPI_COMM_WORLD, &status);
	                if(last == 0) {
	                    last = element[i];
	                }
	                for(int j=0; j<element[i]; j++) {
	                    arr[ind] = recvArray[j];
	                    ind++;
	                }
	            }
			for(int c = 0 ; c < SIZE ; c++)  {
	                	printf("%d ",arr[c]);
	            }
	}
	 else {
	            int newsize; 
	         
	            MPI_Recv(&newsize, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
	            int localArray[newsize]; 
	 	 for(int li = 0; li < newsize; li++) {
	                MPI_Recv(&receive, 1, MPI_INT, 0, 4, MPI_COMM_WORLD, &status);
	                localArray[li] =  receive;
	            }
		sort(localArray,newsize);

		MPI_Send(localArray, newsize, MPI_INT, 0, 5, MPI_COMM_WORLD);
	 }
		
	MPI_Finalize();
}

