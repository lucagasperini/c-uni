#include "utils.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

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

static inline void s_merge_combine(sort_t* arr, sort_t* buffer, size_t start, size_t half, size_t end)
{
        size_t i = start;
        size_t j = half + 1;
        size_t buffer_i = 0;

        while(1) {
                // if i index is still below half but j index is no more below end
                if((i <= half) && !(j <= end)) {
                        // copy remaining elements of i index into the end of arr2 
                        memcpy(buffer + buffer_i, arr + i, (end - buffer_i + 1) * sizeof(sort_t));
                        // stop loop
                        break;
                }
                // if i index is no more below half but j index is below end
                if(!(i <= half) && (j <= end)) {
                        // want to write back before j, since next elements are already sorted
                        end = j - 1;
                        // stop loop
                        break;
                }
                // if both index are out range just exit loop (can happen when element are equal)
                if(!(i <= half) && !(j <= end)) {
                        break;
                }

                if(arr[i] > arr[j]) {
                        // if element at i is bigger than element at j
                        // then add element at j into buffer and increase it 
                        buffer[buffer_i++] = arr[j++];
                } else if(arr[i] < arr[j]) {
                        // if element at j is bigger than element at i
                        // then add element at i into buffer and increase it 
                        buffer[buffer_i++] = arr[i++];
                } else {
                        // if elements are equal, add both to buffer and increase them
                        buffer[buffer_i++] = arr[i++];
                        buffer[buffer_i++] = arr[j++];
                }
        }

        // write back
        memcpy(arr + start, buffer, (end - start + 1) * sizeof(sort_t));
}

static inline void s_merge_divide(sort_t* arr, sort_t* buffer, size_t start, size_t end)
{
        // if one element or invalid size, just return
        if(end - start <= 0) {
                return;
        }
        // es: sorting 8 elements; start = 0, end = 7; 
        // half index = 3
        size_t half = start + ((end - start) / 2);
        
        
        // first subarray = [0,3]
        s_merge_divide(arr, buffer, start, half);
        // first subarray = [4,7]
        s_merge_divide(arr, buffer, half + 1, end);

        s_merge_combine(arr, buffer, start, half, end);
        
}

void merge_sort(sort_t* arr, size_t n)
{
        // just one allocation of buffer element that can hold all sub arrays
        sort_t buffer[n];

        // starting divide et impera
        // C index, if we have 8 element, we sort indexes 0 to 7
        s_merge_divide(arr, buffer, 0, n - 1);


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



static inline size_t s_quicksort_partition(sort_t* arr, size_t low, size_t high)
{
        const sort_t pivot = arr[low];
        sort_t tmp;
        size_t j = low;
        for(size_t i = low + 1; i <= high; i++) {
                if(arr[i] < pivot) {
                        j++;
                        tmp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = tmp;
                }
        }

        arr[low] = arr[j];
        arr[j] = pivot;

        return j;
}

static inline void s_quicksort(sort_t* arr, size_t low, size_t high) 
{
        if(low >= high) {
                return;
        }
        
        if(high - low == 1) {
                if(arr[low] > arr[high]) {
                        sort_t tmp = arr[low];
                        arr[low] = arr[high];
                        arr[high] = tmp;
                }
                return;
        }
        
        size_t p = s_quicksort_partition(arr, low, high);
        s_quicksort(arr, low, p);
        s_quicksort(arr, p+1, high);
}

void quicksort(sort_t* arr, size_t n)
{
        assert(arr != NULL);
        assert(n > 0);

        s_quicksort(arr, 0, n - 1);
}

/*/
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

*/

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


        copy_array_int(ARR_SIZE, arr, a2);

        merge_sort(a2, ARR_SIZE);

        if(!print_array_int(ARR_SIZE, a2)) {
                perror("Error printing array!");
                return 1;
        }
        
        if(!cmp_array_int(ARR_SIZE, a1, a2)) {
                perror("[INSERT/MERGE] Array are not equal");
                return 1;
        }
        
        copy_array_int(ARR_SIZE, arr, a2);


        quicksort(a2, ARR_SIZE);

        if(!print_array_int(ARR_SIZE, a2)) {
                perror("Error printing array!");
                return 1;
        }
        
        if(!cmp_array_int(ARR_SIZE, a1, a2)) {
                perror("[INSERT/QUICK] Array are not equal");
                return 1;
        }
        
        return 0;
}