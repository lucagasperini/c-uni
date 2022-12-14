#include "utils.h"
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 9
#define MAX_VALUE 20


int main(int argc, char** argv)
{
	int arr[ARR_SIZE];

	srand(time(NULL));
	
	if (!fill_array_rand_range_zero(ARR_SIZE, arr, MAX_VALUE)) {
		perror("Error filling the array!");
		return 1;
	}
	
	print_array_int(ARR_SIZE, arr);
	
	int len_asc;
	const int* res_asc = asc_sorted_int_sub(ARR_SIZE, arr, &len_asc);
	if(!res_asc) {
		perror("Error finding longest ascending subarray");
		return 1;
	}
	print_array_int(len_asc, res_asc);

	if(!reverse_array_int(ARR_SIZE, arr)) {
		perror("Error reversing the array");
		return 1;
	}

	int len_desc;
	const int* res_desc = desc_sorted_int_sub(ARR_SIZE, arr, &len_desc);
	if(!res_desc) {
		perror("Error finding longest descending subarray");
		return 1;
	}

	print_array_int(len_desc, res_desc);

	if(len_asc != len_desc) {
		printf("asc -> %d\ndesc -> %d", len_asc, len_desc);
		perror("Error length must be the same of the reverse array!");
		return 1;
	}

	int a1[ARR_SIZE];
	int a2[ARR_SIZE];
	
	if (!fill_array_rand_range_zero(ARR_SIZE, a1, MAX_VALUE)) {
		perror("Error filling the array!");
		return 1;
	}

	if(!copy_array_int(ARR_SIZE, a1, a2)) {
		perror("Error copying the array!");
		return 1;
	}

	if(!reverse_array_int(ARR_SIZE, a2)) {
		perror("Error reversing the array");
		return 1;
	}

	if(!cmp_reverse_array_int(ARR_SIZE, a1, a2)) {
		perror("Error array must be the same of the reverse array!");
		return 1;
	}
	
	return 0;
}
