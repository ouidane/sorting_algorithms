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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			_swap(array + i, min);
			print_array(array, size);
		}
	}
}
