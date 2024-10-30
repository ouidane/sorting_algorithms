#include "sort.h"

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
 * partition_lomuto - Arrange a portion of an array of integers using
 *                    the Lomuto partition scheme (last element as pivot).
 * @arr: The array of integers.
 * @arr_size: The size of the array.
 * @start: The starting index of the portion to arrange.
 * @end: The ending index of the portion to arrange.
 *
 * Return: The final partition index.
 */
int partition_lomuto(int *arr, size_t arr_size, int start, int end)
{
	int *pivot_elem, high, low;

	pivot_elem = arr + end;
	for (high = low = start; low < end; low++)
	{
		if (arr[low] < *pivot_elem)
		{
			if (high < low)
			{
				_swap(arr + low, arr + high);
				print_array(arr, arr_size);
			}
			high++;
		}
	}

	if (arr[high] > *pivot_elem)
	{
		_swap(arr + high, pivot_elem);
		print_array(arr, arr_size);
	}

	return (high);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The starting index of the array partition to order.
 * @end: The ending index of the array partition to order.
 *
 * Return: Nothing
 */
void lomuto_sort(int *array, size_t size, int start, int end)
{
	int pivot;

	if (end - start > 0)
	{
		pivot = partition_lomuto(array, size, start, end);
		lomuto_sort(array, size, start, pivot - 1);
		lomuto_sort(array, size, pivot + 1, end);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 *				using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
