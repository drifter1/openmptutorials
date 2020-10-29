#include <omp.h>
#include <stdio.h>

#define PARALLELISM_ENABLED 1

int main(){
	
	int thread_num;
	
	// Sequential Region
	printf("Hello from Sequential Region\n");
	printf("Number of executing threads is: %d\n", omp_get_num_threads());
	
	// Parallel Region
	#pragma omp parallel if(PARALLELISM_ENABLED) private(thread_num) num_threads(8)
	{
		// Retrieve thread number
		thread_num = omp_get_thread_num();
		
		// Only master thread
		if(thread_num == 0){
			printf("Number of executing threads is: %d\n", omp_get_num_threads());
		}
		
		// All threads
		printf("Hello from thread %d\n", thread_num);
	}
	
	// Sequential Region
	printf("Hello from Sequential Region, again\n");
	printf("Number of executing threads is: %d\n", omp_get_num_threads());
	
	return 0;
}