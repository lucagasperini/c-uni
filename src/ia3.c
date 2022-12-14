#include "utils.h"
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 9
#define MAX_VALUE 20

/**
 * @brief Find the longest ascending sorted subarray on the array
 * 
 * @param sz Size of the integer array, cannot be <= 0
 * @param arr Interger pointer of the array, cannot be NULL
 * @return unsigned int Size of the longest increasing sorted subarray, if invalid argument 0
 */
static inline unsigned int len_asc_sorted_sub(int sz, const int* arr);

/**
 * @brief Find the longest descending sorted subarray on the array
 * 
 * @param sz Size of the integer array, cannot be <= 0
 * @param arr Interger pointer of the array, cannot be NULL
 * @return unsigned int Size of the longest descending sorted subarray, if invalid argument 0
 */
static inline unsigned int len_desc_sorted_sub(int sz, const int* arr);

int main(int argc, char** argv)
{
	int arr[ARR_SIZE];
	
	srand(time(NULL));

	if (!fill_array_rand_range_zero(ARR_SIZE, arr, MAX_VALUE)) {
		perror("Error filling the array!");
		return 1;
	}

	print_array_int(ARR_SIZE, arr);

	unsigned int res_asc = len_asc_sorted_sub(ARR_SIZE, arr);
	if(!res_asc) {
		perror("Error finding longest ascending subarray");
		return 1;
	}

	if(!reverse_array_int(ARR_SIZE, arr)) {
		perror("Error reversing the array");
		return 1;
	}

	print_array_int(ARR_SIZE, arr);

	unsigned int res_desc = len_desc_sorted_sub(ARR_SIZE, arr);
	if(!res_desc) {
		perror("Error finding longest descending subarray");
		return 1;
	}

	if(res_asc != res_desc) {
		printf("asc -> %d\ndesc -> %d", res_asc, res_desc);
		perror("Error length must be the same of the reverse array!");
		return 1;
	}

	printf("The longest sorted subarray is long: %d\n", res_asc);

	return 0;
}

static inline unsigned int len_asc_sorted_sub(int sz, const int* arr)
{
	int len;
	if(asc_sorted_int_sub(sz, arr, &len) == NULL) {
		return 0;
	} else {
		return len;
	}
}

static inline unsigned int len_desc_sorted_sub(int sz, const int* arr)
{
	int len;
	if(desc_sorted_int_sub(sz, arr, &len) == NULL) {
		return 0;
	} else {
		return len;
	}
}