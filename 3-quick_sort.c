#include "sort.h"

void swaper(int *n1, int *n2);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swaper - Swap two integers 
 * @n1: first int
 * @n2: second int
 */
void swaper(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

/**
 * lomuto_partition - use lomuto partition scheme
 * @array: integers
 * @size: size
 * @left: index left
 * @right: index right
 * Return: result
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swaper(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swaper(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - recursif quick sort
 * @array: integers
 * @size: size
 * @left: index left
 * @right: index right
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort using the quicksort
 * @array: integers
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
