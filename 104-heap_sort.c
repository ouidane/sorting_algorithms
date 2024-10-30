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
 * build_max_heap - Build a max heap from an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @base: The index of the base row of the heap.
 * @i: The index of the root node of the heap.
 *
 * Return: Nothing
 */
void build_max_heap(int *array, size_t size, size_t base, size_t i)
{
	size_t left, right, largest;

	left = 2 * i + 1;
	right = 2 * i + 2;
	largest = i;

	if (left < base && array[left] > array[largest])
		largest = left;
	if (right < base && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		_swap(array + i, array + largest);
		print_array(array, size);
		build_max_heap(array, size, base, largest);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		build_max_heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		_swap(array, array + i);
		print_array(array, size);
		build_max_heap(array, size, i, 0);
	}
}
