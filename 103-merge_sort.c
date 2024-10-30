#include "sort.h"

/**
 * merge_subarray - Sort a subarray of integers.
 * @subarray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @start: The start index of the array.
 * @pivot: The pivot index of the array.
 * @end: The end index of the array.
 *
 * Return: Nothing
 */
void merge_subarray(int *subarray, int *buffer, size_t start, size_t pivot,
		size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + start, pivot - start);

	printf("[right]: ");
	print_array(subarray + pivot, end - pivot);

	for (i = start, j = pivot; i < pivot && j < end; k++)
		buffer[k] = (subarray[i] < subarray[j]) ? subarray[i++] : subarray[j++];
	for (; i < pivot; i++)
		buffer[k++] = subarray[i];
	for (; j < end; j++)
		buffer[k++] = subarray[j];
	for (i = start, k = 0; i < end; i++)
		subarray[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarray + start, end - start);
}
/**
 * sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarray: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @start: The start index of the subarray.
 * @end: The end index of the subarray.
 *
 * Return: Nothing
 */
void sort_recursive(int *subarray, int *buffer, size_t start, size_t end)
{
	size_t middle;

	if (end - start > 1)
	{
		middle = start + (end - start) / 2;
		sort_recursive(subarray, buffer, start, middle);
		sort_recursive(subarray, buffer, middle, end);
		merge_subarray(subarray, buffer, start, middle, end);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	sort_recursive(array, buff, 0, size);

	free(buff);
}
