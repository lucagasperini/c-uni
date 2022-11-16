#include "utils.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>

int copy_array(size_t elements, size_t sz, const void* src, void* dest)
{
	if (sz <= 0) 
		return 0;
	if (src == NULL)
		return 0;
	if (dest == NULL)
		return 0;

	if(!memcpy(dest, src, elements * sz))
		return 0;

	return 1;
}


int cmp_array_int(int sz, const int* a1, const int* a2)
{
	if (sz <= 0) 
		return 0;
	if (a1 == NULL)
		return 0;
	if (a2 == NULL)
		return 0;
	
	for (int i = 0; i < sz; i++) {
		if(a1[i] != a2[i]) {
			return 0;
		}
	}

	return 1;
}

int cmp_reverse_array_int(int sz, const int* a1, const int* a2)
{
	if (sz <= 0) 
		return 0;
	if (a1 == NULL)
		return 0;
	if (a2 == NULL)
		return 0;
	
	for (int i = 0; i < sz; i++) {
		if(a1[i] != a2[sz - 1 - i]) {
			return 0;
		}
	}

	return 1;
}

int reverse_array_int(int sz, int* arr)
{
	if (sz <= 0)
		return 0;
	if (arr == NULL)
		return 0;
	
	int i = 0;
	int tmp;
	while (i < sz - i) {
		tmp = arr[i];
		arr[i] = arr[sz - 1 - i];
		arr[sz - 1 - i] = tmp;
		i++;
	}

	return i;
}

int fill_array_rand_range(int sz, int* arr, int max)
{
	if (sz <= 0)
		return 0;
	if (arr == NULL)
		return 0;
	if (max <= 0)
		return 0;

	srand(time(NULL));

	int i = 0;
	while(i < sz)
		arr[i++] = rand() % max;
	
	return i;
}

int print_array_int(int sz, const int *arr)
{
	if (sz <= 0)
		return 0;
	if (arr == NULL)
	 	return 0;
	
	printf("-------- SHOW ARRAY --------\n");

	int i = 0;
	while(i < sz) {
		printf("Value at %d -> %d\n", i, arr[i]);
		i++;
	}
	printf("-------- SHOW ARRAY --------\n");

	return i;
}

int min_array_int_index(int sz, const int *arr)
{
	if (sz <= 0)
		return -1;
	if (arr == NULL)
		return -1;
	if (sz == 1)
		return 0;
	
	int tmp = arr[0];
	int index = 0;

	int i = 1;
	while (i < sz) {
		if (tmp > arr[i]) {
			tmp = arr[i];
			index = i;
		}
		i++;
	}
	return index;
}

int max_array_int_index(int sz, const int *arr)
{
	if (sz <= 0)
		return -1;
	if (arr == NULL)
		return -1;
	if (sz == 1)
		return 0;
	
	int tmp = arr[0];
	int index = 0;

	int i = 1;
	while (i < sz) {
		if (tmp < arr[i]) {
			tmp = arr[i];
			index = i;
		}
		i++;
	}
	return index;
}


int min_array_int_value(int sz, const int *arr)
{
	int index = min_array_int_index(sz, arr);
	if(index == -1)
		return INT_MIN;

	return arr[index];
}

int max_array_int_value(int sz, const int *arr)
{
	int index = min_array_int_index(sz, arr);
	if(index == -1)
		return INT_MAX;
	return arr[index];
}


int avg_array_int(int sz, const int* arr)
{
	if(sz <= 0)
		return INT_MIN;
	if(arr == NULL)
		return INT_MIN;

	int64_t total = 0;
	for(int i = 0; i < sz; i++) {
		total += arr[i];
	}

	return total / sz;
}

const int* asc_sorted_int_sub(int sz, const int* arr, int* len)
{
	if (sz <= 0) 
		return NULL;
	if (arr == NULL)
		return NULL;
	if (len == NULL)
		return NULL;

	// generic starting pointer of a subarray
	const int* start = arr;
	// pointer to the next element of the array
	const int* next = arr + 1;
	// output pointer, pointer to first element of the longest subarray
	const int* out_ptr = arr;
	// default len is 0
	*len = 0;

	while (next < arr + sz) {
		// if previous element is bigger than next we are decreasing
		// then try to record distance (end - start) and set a new starting point
		if(*(next - 1) > *next ) {
			// if distance is bigger than previous distance, then substitute it
			if(next - start > *len) {
				// new longest distance
				*len = next - start;
				// new first element of the longest subarray
				out_ptr = start;
			}
			// set the new starting point
			start = next;
		}
		// go ahead
		next++;
	}

	// special check if longest subarray is at the end of the array
	if(next - start > *len) {
		// new longest distance
		*len = next - start;
		// new first element of the longest subarray
		out_ptr = start;
	}

	//if value is unchanged then we dont record any distance, subarray is whole array 
	if (*len == 0) {
		*len = sz;
	}

	return out_ptr;
}

const int* desc_sorted_int_sub(int sz, const int* arr, int* len)
{
	if (sz <= 0) 
		return NULL;
	if (arr == NULL)
		return NULL;
	if (len == NULL)
		return NULL;

	// generic starting pointer of a subarray
	const int* start = arr;
	// pointer to the next element of the array
	const int* next = arr + 1;
	// output pointer, pointer to first element of the longest subarray
	const int* out_ptr = arr;
	// default len is 0
	*len = 0;

	while (next < arr + sz) {
		// if next element is bigger than previous we are increasing
		// then try to record distance (end - start) and set a new starting point
		if(*(next - 1) < *next ) {
			// if distance is bigger than previous distance, then substitute it
			if(next - start > *len) {
				// new longest distance
				*len = next - start;
				// new first element of the longest subarray
				out_ptr = start;
			}
			// set the new starting point
			start = next;
		}
		// go ahead
		next++;
	}

	// special check if longest subarray is at the end of the array
	if(next - start > *len) {
		// new longest distance
		*len = next - start;
		// new first element of the longest subarray
		out_ptr = start;
	}

	//if value is unchanged then we dont record any distance, subarray is whole array 
	if (*len == 0) {
		*len = sz;
	}


	return out_ptr;
}