#include "utils.h"

#include <stdio.h>

#define ARR_SIZE 100
#define MAX_VALUE 200

typedef int sort_t;

// worst case: O(n^2)
// best case: O(n)
void insert_sort_int(size_t sz, sort_t* arr)
{
        // for all elements
        for(size_t i = 1; i < sz; i++) {
                // takes one element no-sorted copy in a temp var
                sort_t tmp = arr[i];
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
void selection_sort_int(size_t sz, sort_t* arr)
{
        for(size_t i = 0; i < sz; i++) {
                size_t min_index = i;
                for(size_t j = i; j < sz; j++) {
                        if(arr[j] < arr[min_index]) {
                                min_index = j;
                        }
                }
                if(i != min_index) {
                        sort_t swap = arr[i];
                        arr[i] = arr[min_index];
                        arr[min_index] = swap;
                }
        }
}

// worst case: O(n^2)
// best case: O(n)
void bubble_sort2(size_t sz, sort_t* arr)
{
        size_t cmp_index;
        for(size_t i = 1; i < sz; i++) {
                cmp_index = i;
                while(cmp_index && arr[cmp_index-1] > arr[cmp_index]) {
                        sort_t swap = arr[cmp_index-1];
                        arr[cmp_index-1] = arr[cmp_index];
                        arr[cmp_index] = swap;
                        cmp_index--;
                }
        }
}

static void s_merge_arr(sort_t* left, sort_t* right)
{
        //TODO
}

void merge_sort_int(size_t sz, sort_t* arr)
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
                        sort_t swap = arr[0];
                        arr[0] = arr[1];
                        arr[1] = swap;
                }
        }
        
}

// worst case: O(n^2)
// best case: O(n)
void bubble_sort(size_t sz, sort_t* arr)
{
        if(sz == 0)
                return;
        if(arr == NULL)
                return;
        
        for(int j = sz; j > 1; j--) {
                for(int i = 1; i < j; i++) {
                        if(arr[i - 1] > arr[i]) {
                                sort_t swap = arr[i];
                                arr[i] = arr[i-1];
                                arr[i-1] = swap; 
                        }
                }
        }
}

static void s_quicksort_partition(sort_t* arr, size_t low, size_t high)
{
        
}

static void s_quicksort(sort_t* arr, size_t low, size_t high)
{
        if(low < high) {
                s_quicksort_partition(arr, low, high);

        }
}

void quick_sort_int(size_t sz, sort_t* arr)
{
        size_t half_left = sz / 2;
        sort_t pivot = arr[half_left];

        if(sz == 0 || sz == 1) 
                return;


        if(sz > 2) {
                merge_sort_int(half_left, arr);
                //merge_sort_int(half_right, arr + half_left);
        } else {
                if(arr[0] > arr[1]) {
                        sort_t swap = arr[0];
                        arr[0] = arr[1];
                        arr[1] = swap;
                }
        }
        
}



int main(int argc, char** argv)
{
        sort_t arr[ARR_SIZE];
        sort_t a1[ARR_SIZE];
        sort_t a2[ARR_SIZE];

        srand(time(NULL));

        fill_array_rand_range_sign(ARR_SIZE, arr, MAX_VALUE);

/*
        if(!print_array_int(ARR_SIZE, arr)) {
                perror("Error printing array!");
                return 1;
        }
*/
        if(!copy_array_int(ARR_SIZE, arr, a1)) {
                return 1;
        }

        insert_sort_int(ARR_SIZE, a1);
/*
        if(!print_array_int(ARR_SIZE, a1)) {
                perror("Error printing array!");
                return 1;
        }
*/
        if(!copy_array_int(ARR_SIZE, arr, a2)) {
                return 1;
        }

        selection_sort_int(ARR_SIZE, a2);
/*
        if(!print_array_int(ARR_SIZE, a2)) {
                perror("Error printing array!");
                return 1;
        }
*/
        if(!cmp_array_int(ARR_SIZE, a1, a2)) {
                perror("[INSERT/SELECTION] Array are not equal");
                return 1;
        }

        copy_array_int(ARR_SIZE, arr, a2);

        bubble_sort(ARR_SIZE, a2);
/*
        if(!print_array_int(ARR_SIZE, a2)) {
                perror("Error printing array!");
                return 1;
        }
*/
        if(!cmp_array_int(ARR_SIZE, a1, a2)) {
                perror("[INSERT/BUBBLE] Array are not equal");
                return 1;
        }

        copy_array_int(ARR_SIZE, arr, a2);

        bubble_sort2(ARR_SIZE, a2);

        if(!print_array_int(ARR_SIZE, a2)) {
                perror("Error printing array!");
                return 1;
        }
        
        if(!cmp_array_int(ARR_SIZE, a1, a2)) {
                perror("[INSERT/BUBBLE2] Array are not equal");
                return 1;
        }


        return 0;
}