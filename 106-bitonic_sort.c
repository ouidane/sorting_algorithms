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
 * sort_bitonic - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @n: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @length: The size of the sequence to sort.
 * @direction: The direction to sort in.
 *
 * Return: Nothing
 */
void sort_bitonic(int *array, size_t n, size_t start, size_t length,
		char direction)
{
	size_t i, step = length / 2;

	if (length > 1)
	{
		for (i = start; i < start + step; i++)
		{
			if ((direction == UP && array[i] > array[i + step]) ||
			    (direction == DOWN && array[i] < array[i + step]))
				_swap(array + i, array + i + step);
		}
		sort_bitonic(array, n, start, step, direction);
		sort_bitonic(array, n, start + step, step, direction);
	}
}
/**
 * build_bitonic - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @n: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @length: The size of a block of the building bitonic sequence.
 * @direction: The direction to sort the bitonic sequence block in.
 */
void build_bitonic(int *array, size_t n, size_t start, size_t length,
		char direction)
{
	size_t cut = length / 2;
	char *str = (direction == UP) ? "UP" : "DOWN";

	if (length > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", length, n, str);
		print_array(array + start, length);

		build_bitonic(array, n, start, cut, UP);
		build_bitonic(array, n, start + cut, cut, DOWN);
		sort_bitonic(array, n, start, length, direction);

		printf("Result [%lu/%lu] (%s):\n", length, n, str);
		print_array(array + start, length);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	build_bitonic(array, size, 0, size, UP);
}
