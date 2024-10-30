#include "sort.h"

/**
 * find_max - Find the maximum value in an array of integers.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int find_max(int *arr, int size)
{
	int max, i;

	for (max = arr[0], i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return (max);
}

/**
 * counting_sort_radix - Sort the significant digits of an array of integers
 *                       in ascending order.
 * @arr: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 *
 * Return: Nothing
 */
void counting_sort_radix(int *arr, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(arr[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(arr[i] / sig) % 10] - 1] = arr[i];
		count[(arr[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		arr[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = find_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		counting_sort_radix(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
