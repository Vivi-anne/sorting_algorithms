#include "sort.h"

/**
 * partition - partition the array into subarrays based on a pivot
 * @array: array to sort
 * @min: minimum index of partition
 * @max: maximum index of partition
 * @size: size of the array
 * Return: the partition index
 */
size_t partition(int *array, ssize_t min, ssize_t max, size_t size)
{
    int swap, pivot;
    ssize_t i, j;

    pivot = array[max];
    i = min - 1;

    for (j = min; j < max; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                /* Swap array[i] and array[j] */
                swap = array[i];
                array[i] = array[j];
                array[j] = swap;
                print_array(array, size);
            }
        }
    }
    if (array[max] < array[i + 1])
    {
        /* Swap array[i + 1] and array[max] */
        swap = array[i + 1];
        array[i + 1] = array[max];
        array[max] = swap;
        print_array(array, size);
    }

    /* Return the partition index */
    return (i + 1);
}

/**
 * quicksort - sort the array using Quick Sort algorithm
 * @array: array to sort
 * @min: minimum index of partition
 * @max: maximum index of partition
 * @size: size of the array
 */
void quicksort(int *array, ssize_t min, ssize_t max, size_t size)
{
    ssize_t pivot;

    /* If min < max, partition the array and sort recursively */
    if (min < max)
    {
        pivot = partition(array, min, max, size);
        quicksort(array, min, pivot - 1, size);
        quicksort(array, pivot + 1, max, size);
    }
}

/**
 * quick_sort - sort the array using Quick Sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    /* Check if the array is empty or has only one element */
    if (array == NULL || size < 2)
        return;

    /* Sort the array using Quick Sort algorithm */
    quicksort(array, 0, size - 1, size);
}

