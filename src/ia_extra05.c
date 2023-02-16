#include "utils.h"

typedef data_t;

// Works only for sorted array
// Time Complexity O(log(n))
int s_binary_search(data_t needle, data_t* base_ptr, size_t start, size_t end) 
{
        if(end < start) {
                return -1;
        }

        size_t m = (end + start)/2;

        if(base_ptr[m] == needle) {
                return m;
        } else if(base_ptr[m] > needle) {
                return s_binary_search(needle, base_ptr, start, m - 1);
        } else {
                return s_binary_search(needle, base_ptr, m + 1, end);
        }
}

int binary_search(data_t needle, data_t* ptr, size_t num)
{
        if(ptr == NULL) {
                return -1;
        }
        return s_binary_search(needle, ptr, 0, num - 1);
}


int main(int argc, char** argv)
{
        data_t d[10] = {0, 2, 3, 4, 5, 6, 45, 48, 522, 5454};
        for(size_t i = 0; i < 10; i++)
                printf("%d\n", binary_search(d[i], d, 10));
        
        return 0;
}