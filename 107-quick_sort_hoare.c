#include "sort.h"
#include <stdio.h>
/**
 * _swap - Swap two integers in an array.
 * @i: The first integer to swap.
 * @j: The second integer to swap.
 *
 * Return: Nothing.
 */
void _swap(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * partition_hoare - Order a subset of an array of integers
 *                   according to the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int partition_hoare(int *array, size_t size, int start, int end)
{
	int pivot, above, below;

	pivot = array[end];
	for (above = start - 1, below = end + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			_swap(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * quick_sort_recursive_hoare - Implement the quicksort algorithm recursively.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The starting index of the array partition to order.
 * @end: The ending index of the array partition to order.
 *
 * Return: Nothing
 */
void quick_sort_recursive_hoare(int *array, size_t size, int start, int end)
{
	int pivot_index;

	if (end - start > 0)
	{
		pivot_index = partition_hoare(array, size, start, end);
		quick_sort_recursive_hoare(array, size, start, pivot_index - 1);
		quick_sort_recursive_hoare(array, size, pivot_index, end);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive_hoare(array, size, 0, size - 1);
}
