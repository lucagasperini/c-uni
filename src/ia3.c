#include "utils.h"
#include <stdio.h>
#include <sys/types.h>

#define ARR_SIZE 9
#define MAX_VALUE 20

/**
 * @brief Find the longest ascending sorted subarray on the array
 * 
 * @param sz Size of the integer array, cannot be <= 0
 * @param arr Interger pointer of the array, cannot be NULL
 * @return uint Size of the longest increasing sorted subarray, if invalid argument 0
 */
uint len_asc_sorted_sub(int sz, const int* arr);

/**
 * @brief Find the longest descending sorted subarray on the array
 * 
 * @param sz Size of the integer array, cannot be <= 0
 * @param arr Interger pointer of the array, cannot be NULL
 * @return uint Size of the longest descending sorted subarray, if invalid argument 0
 */
uint len_desc_sorted_sub(int sz, const int* arr);

int main(int argc, char** argv)
{
	int arr[ARR_SIZE];
	if (!fill_array_rand_range(ARR_SIZE, arr, MAX_VALUE)) {
		perror("Error filling the array!");
		return 1;
	}

	print_array_int(ARR_SIZE, arr);

	uint res_asc = len_asc_sorted_sub(ARR_SIZE, arr);
	if(!res_asc) {
		perror("Error finding longest ascending subarray");
		return 1;
	}

	if(!reverse_array_int(ARR_SIZE, arr)) {
		perror("Error reversing the array");
		return 1;
	}

	print_array_int(ARR_SIZE, arr);

	uint res_desc = len_desc_sorted_sub(ARR_SIZE, arr);
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

uint len_asc_sorted_sub(int sz, const int* arr)
{
	if (sz <= 0) 
		return 0;
	if (arr == NULL)
		return 0;

	// starting point is zero
	// ending point is one (to get end - 1)
	// length is zero, just because we can check if all values are equal
	int start = 0, end = 1, len = 0;

	while (end < sz) {
		// if where are decreasing then record distance (end - start)
		if(arr[end - 1] > arr[end]) {
			// if distance is bigger than previous distance, then substitute it
			if(end - start > len) {
				len = end - start;
			}
			// fix the new starting point
			start = end;
		}
		// go ahead
		end++;
	}

	// if the longest subarray is at the end, remember to check it and update it
	if(end - start > len) {
		len = end - start;
	}

	// handling special case all values are equal
	if(len == 0)
		return sz;

	return len;
}

uint len_desc_sorted_sub(int sz, const int* arr)
{
	if (sz <= 0) 
		return 0;
	if (arr == NULL)
		return 0;

	// starting point is zero
	// ending point is one (to get end - 1)
	// length is zero, just because we can check if all values are equal
	int start = 0, end = 1, len = 0;

	while (end < sz) {
		// if where are increasing then record distance (end - start)
		if(arr[end - 1] < arr[end]) {
			// if distance is bigger than previous distance, then substitute it
			if(end - start > len) {
				len = end - start;
			}
			// fix the new starting point
			start = end;
		}
		// go ahead
		end++;
	}

	// if the longest subarray is at the end, remember to check it and update it
	if(end - start > len) {
		len = end - start;
	}

	// handling special case all values are equal
	if(len == 0)
		return sz;

	return len;
}