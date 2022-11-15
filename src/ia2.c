#include "utils.h"
#include <limits.h>
#include <stdio.h>

#define ARR_SIZE 10
#define MAX_VALUE 1024

int main(int argc, char** argv)
{
	int arr[ARR_SIZE];
	fill_array_rand_range(ARR_SIZE, arr, MAX_VALUE);
	print_array(ARR_SIZE, arr);

	int res = avg_array_int(ARR_SIZE, arr);
	if (res == INT_MIN){
		perror("Error fetching average value in the array!");
		return 1;
	}
	
	printf("Array average as integer is %d\n", res);

	return 0;
}