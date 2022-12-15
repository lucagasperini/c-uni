#include "utils.h"

#include <stdio.h>

#define ARR_SIZE 100
#define MAX_VALUE 200

// worst case: O(n^2)
// best case: O(n)
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

// worst case: O(n^2)
// best case: O(n^2)
void selection_sort_int(size_t sz, int* arr)
{
        for(size_t i = 0; i < sz; i++) {
                size_t min_index = i;
                for(size_t j = i; j < sz; j++) {
                        if(arr[j] < arr[min_index]) {
                                min_index = j;
                        }
                }
                if(i != min_index) {
                        int swap = arr[i];
                        arr[i] = arr[min_index];
                        arr[min_index] = swap;
                }
        }
}

// worst case: O(n^2)
// best case: O(n)
void bubble_sort_int(size_t sz, int* arr)
{
        size_t cmp_index;
        for(size_t i = 1; i < sz; i++) {
                cmp_index = i;
                while(cmp_index && arr[cmp_index-1] > arr[cmp_index]) {
                        int swap = arr[cmp_index-1];
                        arr[cmp_index-1] = arr[cmp_index];
                        arr[cmp_index] = swap;
                        cmp_index--;
                }
        }
}

static void s_merge_arr(int* left, int* right)
{
        //TODO
}

void merge_sort_int(size_t sz, int* arr)
{
        size_t half_left = sz / 2;
        size_t half_right = sz - half_left;

        if(sz == 0 || sz == 1) 
                return;


        if(sz > 2) {
                merge_sort_int(half_left, arr);
                merge_sort_int(half_right, arr + half_left);
        } else {
                if(arr[0] > arr[1]) {
                        int swap = arr[0];
                        arr[0] = arr[1];
                        arr[1] = swap;
                }
        }
        
}

static void s_quicksort_partition(int* arr, size_t low, size_t high)
{
        
}

static void s_quicksort(int* arr, size_t low, size_t high)
{
        if(low < high) {
                s_quicksort_partition(arr, low, high);

        }
}

void quick_sort_int(size_t sz, int* arr)
{
        size_t half_left = sz / 2;
        int pivot = arr[half_left];

        if(sz == 0 || sz == 1) 
                return;


        if(sz > 2) {
                merge_sort_int(half_left, arr);
                //merge_sort_int(half_right, arr + half_left);
        } else {
                if(arr[0] > arr[1]) {
                        int swap = arr[0];
                        arr[0] = arr[1];
                        arr[1] = swap;
                }
        }
        
}



int main(int argc, char** argv)
{
        int arr[ARR_SIZE];
        int a1[ARR_SIZE];
        int a2[ARR_SIZE];

        srand(time(NULL));

        fill_array_rand_range_sign(ARR_SIZE, arr, MAX_VALUE);


        if(!print_array_int(ARR_SIZE, arr)) {
                perror("Error printing array!");
                return 1;
        }

        if(!copy_array_int(ARR_SIZE, arr, a1)) {
                return 1;
        }

        insert_sort_int(ARR_SIZE, a1);

        if(!print_array_int(ARR_SIZE, a1)) {
                perror("Error printing array!");
                return 1;
        }

        if(!copy_array_int(ARR_SIZE, arr, a2)) {
                return 1;
        }

        selection_sort_int(ARR_SIZE, a2);

        if(!print_array_int(ARR_SIZE, a2)) {
                perror("Error printing array!");
                return 1;
        }

        if(!cmp_array_int(ARR_SIZE, a1, a2)) {
                perror("[INSERT/SELECTION] Array are not equal");
                return 1;
        }

        copy_array_int(ARR_SIZE, arr, a2);

        bubble_sort_int(ARR_SIZE, a2);

        if(!print_array_int(ARR_SIZE, a2)) {
                perror("Error printing array!");
                return 1;
        }

        if(!cmp_array_int(ARR_SIZE, a1, a2)) {
                perror("[INSERT/BUBBLE] Array are not equal");
                return 1;
        }

        copy_array_int(ARR_SIZE, arr, a2);

        merge_sort_int(ARR_SIZE, a2);

        if(!print_array_int(ARR_SIZE, a2)) {
                perror("Error printing array!");
                return 1;
        }

        if(!cmp_array_int(ARR_SIZE, a1, a2)) {
                perror("[INSERT/MERGE] Array are not equal");
                return 1;
        }


        return 0;
}