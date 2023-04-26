#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the selection sort algorithm
 *
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
    unsigned long int i, j, smallest_idx;
    int *temp;

    /* check if array is null or has less than 2 elements */
    if (array == NULL || size < 2)
        return;

    /* iterate over the array */
    for (i = 0; i < size - 1; i++)
    {
        /* assume the current element is the smallest */
        smallest_idx = i;

        /* find the smallest element in the unsorted part of the array */
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[smallest_idx])
                smallest_idx = j;
        }

        /* swap the smallest element with the current element */
        if (smallest_idx != i)
        {
            temp = &array[i];
            array[i] = array[smallest_idx];
            array[smallest_idx] = *temp;

            /* print the array after every swap */
            print_array(array, size);
        }
    }
}

