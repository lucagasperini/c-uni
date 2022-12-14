#include "utils.h"

#include <stdio.h>

#define ARR_SIZE 10
#define MAX_VALUE 20

void insert_sort_int(size_t sz, int* arr)
{
        // for all elements
        for(size_t i = 1; i < sz; i++) {
                // takes one element no-sorted copy in a temp var
                int tmp = arr[i];
                // takes index copy (last sorted + 1)
                size_t j = i;
                // while we dont reach the end of the array or we dont reach position 
                while(j && arr[j - 1] > tmp) {
                        // shift a element to right
                        arr[j] = arr[j - 1];
                        j--;

                }
                // place the element in the right place
                arr[j] = tmp;
        }
}

int main(int argc, char** argv)
{
        int arr[ARR_SIZE];

        srand(time(NULL));

        fill_array_rand_range_sign(ARR_SIZE, arr, MAX_VALUE);

        if(!print_array_int(ARR_SIZE, arr)) {
                perror("Error printing array!");
                return 1;
        }

        insert_sort_int(ARR_SIZE, arr);

        if(!print_array_int(ARR_SIZE, arr)) {
                perror("Error printing array!");
                return 1;
        }

        return 0;
}