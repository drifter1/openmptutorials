#include <omp.h>
#include <stdio.h>

int main(){
	
	// Sequential Region
	printf("Hello from Sequential Region\n");
	printf("Number of executing threads is: %d\n", omp_get_num_threads());
	
	// Parallel Region
	#pragma omp parallel num_threads(8)
	{
		// Only master thread
		if(omp_get_thread_num() == 0){
			printf("Number of executing threads is: %d\n", omp_get_num_threads());
		}
		
		// All threads
		printf("Hello from thread %d\n", omp_get_thread_num());
	}
	
	// Sequential Region
	printf("Hello from Sequential Region, again\n");
	printf("Number of executing threads is: %d\n", omp_get_num_threads());
	
	return 0;
}