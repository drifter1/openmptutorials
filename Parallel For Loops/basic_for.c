#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PARALLELISM_ENABLED 1

#define M 800
#define N 800
#define P 800

int main(){
	/* declare integer arrays */
	int A[M][N], B[N][P], C[M][P];
	
	/* loop counters */
	int i, j, k;
	
	/* Calculation time */
	time_t start_t, end_t;
	double total;
	
	/* initialize arrays */
	srand(time(NULL));
	
	for(i = 0; i < M; i++){
		for(j = 0; j < N; j++){
			/* random value in range (0, 100] */
			A[i][j] = 1 + rand() % 100; 
		}
	}
	
	for(i = 0; i < N; i++){
		for(j = 0; j < P; j++){
			/* random value in range (0, 100] */
			B[i][j] = 1 + rand() % 100; 
		}
	}
	
	for(i = 0; i < M; i++){
		for(j = 0; j < P; j++){
			C[i][j] = 0;
		}
	}
	
	/* calculate dot product with parallel for loop */
	start_t = time(NULL);
	
	#pragma omp parallel for private(i, j, k) if(PARALLELISM_ENABLED)
	for(i = 0; i < M; i++){
		for(j = 0; j < P; j++){
			for(k = 0; k < N; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	end_t = time(NULL);
	
	/* Calculate and print Calculation time */
	total = difftime(end_t, start_t);
	printf("Loop execution took: %.2f seconds (parallelism enabled: %d)\n", total, PARALLELISM_ENABLED);
	
	return 0;	
}
