#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @i: The first integer to swap.
 * @j: The second integer to swap.
 */
void swap_ints(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: given array.
 * @size: The size of the array.
 * @start: The starting index of the sequence.
 * @flow: The direction to sort in.
 * @seq: The size of the sequence to sort.
 */
void bitonic_merge(int *array, size_t size, size_t start,
size_t seq, char flow)
{
	size_t a, jump = seq / 2;

	if (seq > 1)
	{
		for (a = start; a < start + jump;a++)
		{
			if ((flow == UP && array[a] > array[a + jump]) ||
			    (flow == DOWN && array[a] < array[a + jump]))
				swap_ints(array + a, array + a + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: Given array
 * @size: The size of the array.
 * @start: The starting index of a block.
 * @flow: The direction to sort the bitonic sequence block in.
 * @seq: The size of a block of the building bitonic sequence.
 */
void bitonic_seq(int *array, unsigned long int size, size_t start,
unsigned long int seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order.
 * @size: The size of the array.
 * @array: An array of integers.
 *
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
