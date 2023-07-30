#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 *@a: The fisrt integer to swap
 *@b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *hoare_partition - Organise the array for quick hoare sort
 *@array: The array to sort
 *@size: The size of the rray
 *@left: The starting index of the subset to order
 *@right: The ending index of the subset to order
 *Return: The partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}
	return (above);
}

/**
 *hoare_sort - Implement the quicksort algorithm recursively
 *@array: An array to sort
 *@size: The size of the array
 *@left: The starting index of the array partition
 *@right: The ending index of the array partition
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 *quick_sort_hoare - Sort an array using quicksort algorithm
 *@array: An array to sort
 *@size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}