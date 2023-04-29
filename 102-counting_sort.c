
#include "sort.h"

/**
 * counting_sort - sorts an array of integers using counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int i, max_val;
	int *count_array = NULL, *copy_array = NULL;
	size_t j, temp, total = 0;

	if (array == NULL || size < 2)
		return;

	copy_array = malloc(sizeof(int) * size);
	if (copy_array == NULL)
		return;

	/* Find the maximum value in the array */
	for (j = 0, max_val = 0; j < size; j++)
	{
		copy_array[j] = array[j];
		if (array[j] > max_val)
			max_val = array[j];
	}

	count_array = malloc(sizeof(int) * (max_val + 1));
	if (count_array == NULL)
	{
		free(copy_array);
		return;
	}

	/* Initialize the count array with all zeros */
	for (i = 0; i <= max_val; i++)
		count_array[i] = 0;

	/* Count the number of occurrences of each element */
	for (j = 0; j < size; j++)
		count_array[array[j]] += 1;

	/* Calculate the cumulative sum of counts */
	for (i = 0; i <= max_val; i++)
	{
		temp = count_array[i];
		count_array[i] = total;
		total += temp;
	}

	/* Copy the elements from copy_array to array in sorted order */
	for (j = 0; j < size; j++)
	{
		array[count_array[copy_array[j]]] = copy_array[j];
		count_array[copy_array[j]] += 1;
	}

	/* Print the count_array */
	print_array(count_array, max_val + 1);

	/* Free allocated memory */
	free(count_array);
	free(copy_array);
}





