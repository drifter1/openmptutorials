#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	/* implicit barrier */
	#pragma omp parallel
	{
		printf("Thread %d running inside of the parallel region\n", omp_get_thread_num());
	}

	printf("Main thread after implicit barrier!\n");

	/* implicit barrier and multiple messages */
	#pragma omp parallel
	{
		printf("Thread %d running before explicit barrier\n", omp_get_thread_num());
		printf("Thread %d running after explicit barrier\n", omp_get_thread_num());
	}
	
	printf("Main thread after implicit barrier!\n");

	/* explicit and implicit barrier */
	#pragma omp parallel
	{
		printf("Thread %d running before explicit barrier\n", omp_get_thread_num());

		#pragma omp barrier

		printf("Thread %d running after explicit barrier\n", omp_get_thread_num());
	}

	printf("Main thread after implicit and explicit barriers!\n");
	
	return 0;
}
