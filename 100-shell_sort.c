#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 *              using the Shell sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    /* Ensure array exists and has at least two elements */
    if (array == NULL || size == 1)
        return;

    /* Start with a big gap, then reduce the gap */
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        /* Do an insertion sort for each gap */
        for (i = gap; i < size; i++)
        {
            /* Save current element to temp */
            temp = array[i];

            /* Shift elements until the correct position is found */
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }

            /* Insert the saved element into its correct position */
            array[j] = temp;
        }

        /* Print the array after each iteration */
        print_array(array, size);
    }
}

