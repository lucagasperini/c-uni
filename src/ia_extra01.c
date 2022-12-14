#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ARR_SIZE 10
#define MAX_VALUE 20

int* search_max_subarray_n2(size_t sz, int* arr, size_t* res_length);

int main(int argc, char** argv)
{
        int arr[ARR_SIZE];

        srand(time(NULL));

        fill_array_rand_range_sign(ARR_SIZE, arr, MAX_VALUE);

        if(!print_array_int(ARR_SIZE, arr)) {
                perror("Error printing array!");
                return 1;
        }
        
        size_t len;
        int* ptr = search_max_subarray_n2(ARR_SIZE, arr, &len);

        if(ptr == NULL || len == 0) {
                perror("Error searching subarray");
                return 1;
        }

        if(!print_array_int(len, ptr)) {
                perror("Error printing array!");
                return 1;
        }


        return 0;
}

int* search_max_subarray_n2(size_t sz, int* arr, size_t* res_length)
{
        if(sz == 0)
                return NULL;
        if(arr == NULL)
                return NULL;
        
        *res_length = sz;
        int* res_ptr = arr;
        long long int max = LLONG_MIN;
        long long int tmp;

        for(size_t i = 0; i < sz; i++) {
                tmp = 0;
                for(size_t j = i; j < sz; j++) {
                        tmp += arr[j];
                        if(max < tmp) {
                               *res_length = j + 1 - i;
                               res_ptr = arr + i;
                               max = tmp;
                        }
                }
        }

        return res_ptr;

}
