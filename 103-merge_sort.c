#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sorted_arrays - sorts and merges two sub-arrays
 * @start: starting index of first sub-array
 * @middle: ending index of first sub-array, starting index of second sub-array
 * @end: ending index of second sub-array
 * @dest: destination array for merged data
 * @source: source array for data to be merged
 *
 * Return: void
 */
void merge_sorted_arrays(size_t start, size_t middle, size_t end, int *dest, int *source)
{
    size_t i, j, k;

    printf("Merging...\n");
    printf("[Left]: ");
    print_array(source + start, middle - start);
    printf("[Right]: ");
    print_array(source + middle, end - middle);

    i = start;  // index of first sub-array
    j = middle;  // index of second sub-array

    for (k = start; k < end; k++)
    {
        if (i < middle && (j >= end || source[i] <= source[j]))
        {
            dest[k] = source[i];  // copy from first sub-array
            i++;
        }
        else
        {
            dest[k] = source[j];  // copy from second sub-array
            j++;
        }
    }

    printf("[Done]: ");
    print_array(dest + start, end - start);
}

/**
 * recursive_merge_sort - recursively splits the array, sorts and merges
 * @start: starting index (inclusive)
 * @end: ending index (exclusive)
 * @array: the array to sort
 * @clone: a clone of the array
 *
 * Return: void
 */
void recursive_merge_sort(size_t start, size_t end, int *array, int *clone)
{
    size_t middle;

    if (end - start < 2)  // base case: single element or empty array
        return;

    middle = (start + end) / 2;  // middle index

    recursive_merge_sort(start, middle, array, clone);  // sort left half
    recursive_merge_sort(middle, end, array, clone);  // sort right half

    merge_sorted_arrays(start, middle, end, array, clone);  // merge sorted sub-arrays

    // copy merged array from destination back to source
    for (middle = start; middle < end; middle++)
        clone[middle] = array[middle];
}

/**
 * merge_sort - sorts an array of integers using the merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
    size_t i;
    int *clone;

    if (array == NULL || size < 2)  // check for invalid inputs
        return;

    clone = malloc(sizeof(int) * size);  // create a clone of the array for merging
    if (clone == NULL)
        return;

    // copy original array to clone
    for (i = 0; i < size; i++)
        clone[i] = array[i];

    // sort the original array using the clone for merging
    recursive_merge_sort(0, size, array, clone);

    free(clone);  // free memory allocated for clone
}

