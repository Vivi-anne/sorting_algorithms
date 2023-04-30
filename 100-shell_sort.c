#include "sort.h"

/**
 * swap - swaps two values of array
 * @array: the array
 * @a: first element's index
 * @b: second element's index
 *
 * Return: void
 */
void swap(int *array, long int a, long int b)
{
	int tmp;

	if (!array)
		return;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order
 *              using the Shell sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	long int a, next, k, j;

	if (array == NULL || (size == 1))
		return;

	a = next = 1;
	while ((size_t)next < size)
	{
		a = next;
		next = (a * 3) + 1;
	}

	while (a >= 1)
	{
		for (j = a; (size_t)j < size; j++)
		{
			for (k = j - a; k >= 0; k -= a)
			{
				if (array[k] > array[k + a])
					swap(array, k, k + a);
				else
					break;
			}
		}
		a = (a - 1) / 3;
		print_array(array, size);
	}
}
