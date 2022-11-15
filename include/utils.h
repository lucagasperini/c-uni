#ifndef UNI_UTILS_H
#define UNI_UTILS_H

/**
 * @brief Takes an integer array and fill it with a N as random value where 0 <= N < max
 * 
 * @param sz Size of the integer array, cannot be <= 0
 * @param arr Interger pointer of the array, cannot be NULL
 * @param max Maximum value on the array, cannot be <= 0
 * @return int Number of elements filled on array 
 */
int fill_array_rand_range(int sz, int* arr, int max);

/**
 * @brief Print an array of integer
 * 
 * @param sz Size of the integer array, cannot be <= 0
 * @param arr Interger pointer of the array, cannot be NULL
 * @return int Number of elements printed on array 
 */
int print_array(int sz, int* arr);

/**
 * @brief Search the index of the minimum value on the array of integers
 * 
 * @param sz Size of the integer array, cannot be <= 0
 * @param arr Interger pointer of the array, cannot be NULL
 * @return int Index of the minimum value on the array, if invalid -1
 */
int min_array_index(int sz, int* arr);

/**
 * @brief Search the index of the maximum value on the array of integers
 * 
 * @param sz Size of the integer array, cannot be <= 0
 * @param arr Interger pointer of the array, cannot be NULL
 * @return int Index of the maximum value on the array, if invalid return -1
 */
int max_array_index(int sz, int* arr);

/**
 * @brief Search the minimum value on the array of integers
 * 
 * @param sz Size of the integer array, cannot be <= 0
 * @param arr Interger pointer of the array, cannot be NULL
 * @return int Index of the minimum value on the array, if invalid return INT_MIN constant
 */
int min_array_value(int sz, int* arr);

/**
 * @brief Search the maximum value on the array of integers
 * 
 * @param sz Size of the integer array, cannot be <= 0
 * @param arr Interger pointer of the array, cannot be NULL
 * @return int Index of the maximum value on the array, if invalid return INT_MAX constant
 */
int max_array_value(int sz, int* arr);

/**
 * @brief Calculate the average of the array of integer
 * 
 * @param sz Size of the integer array, cannot be <= 0
 * @param arr Interger pointer of the array, cannot be NULL
 * @return int Number average of the array 
 */
int avg_array_int(int sz, int* arr);

#endif