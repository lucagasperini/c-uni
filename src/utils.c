#include "utils.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

int fill_array_rand_range(int sz, int *arr, int max)
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

int print_array(int sz, int *arr)
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

int min_array_index(int sz, int *arr)
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

int max_array_index(int sz, int *arr)
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


int min_array_value(int sz, int *arr)
{
	int index = min_array_index(sz, arr);
	if(index == -1)
		return INT_MIN;

	return arr[index];
}

int max_array_value(int sz, int *arr)
{
	int index = min_array_index(sz, arr);
	if(index == -1)
		return INT_MAX;
	return arr[index];
}


int avg_array_int(int sz, int* arr)
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