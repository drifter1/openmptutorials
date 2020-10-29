#include <omp.h>
#include <stdio.h>

int main(){
	
	// Sequential Region
	printf("Hello from Sequential Region\n");
	
	// Parallel Region
	#pragma omp parallel
	{
		printf("Hello from Parallel Region\n");
	}
	
	// Sequential Region
	printf("Hello from Sequential Region, again\n");
	
	return 0;
}
