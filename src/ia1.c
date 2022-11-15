
#include "utils.h"
#include <stdio.h>

#define ARR_SIZE 10
#define MAX_VALUE 1024

int main(int argc, char** argv)
{
        int arr[ARR_SIZE];
	fill_array_rand_range(ARR_SIZE, arr, MAX_VALUE);

	print_array(ARR_SIZE, arr);

	int min_index = min_array_index(ARR_SIZE, arr);
	int max_index = max_array_index(ARR_SIZE, arr);
	if (min_index == -1 || max_index == -1) {
		perror("Error while fetching min or max index of the array!");
		return 1;
	}
	int min_value = arr[min_index];
	int max_value = arr[max_index];

	printf("Min in %d -> %d\nMax in %d -> %d\n",
		min_index, min_value, max_index, max_value);


        return 0;
}