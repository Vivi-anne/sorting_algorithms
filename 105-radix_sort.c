#include "sort.h"
#include <stdlib.h>

#define BASE 10

void count_sort(int *, size_t, int);
int largest_number(int *array, size_t size);

/**
 * radix_sort - sorts array of integers in ascending order
 * @array: array given
 * @size: size of an array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, j;

	if (!array || (size == 1))
		return;

	max = largest_number(array, size);
	for (i = j; (max / j) > 0; j *= BASE)
	{
		count_sort(array, size, j);
		print_array(array, size);
	}
}

/**
 * count_sort - sorts an array 
 * @array: the array given
 * @size: size of an array
 * @place: to get digit to be sorted 
 *
 * Return: void
 */
void count_sort(int *array, size_t size, int place)
{
	int count[BASE], a;
	int *tmp;
	long int j;

	if (!array)
		return;

	for (j = 0; j < BASE; j++)
		count[j] = 0;
	for (j = 0; (size_t)j < size; j++)
	{
		a = (array[j] / place) % BASE;
		count[a]++;
	}
	for (j = 1; j < BASE; j++)
		count[j] += count[j - 1];

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	for (j = size - 1; j >= 0; j--)
	{
		d = (array[j] / place) % BASE;
		tmp[(count[a]--) - 1] = array[j];
	}
	for (j = 0; (size_t)j < size; j++)
		array[j] = tmp[j];
	free(tmp);
}

/**
 * largest_number - largest number in an array
 * @array: given array
 * @size: size of the array
 *
 * Return: largest number
 */
int largest_number(int *array, size_t size)
{
	int max;
	size_t j;

	if (!array)
		return (0);

	max = array[0];
	for (j = 1; j < size; j++)
		if (array[j] > max)
			max = array[j];
	return (max);
}
