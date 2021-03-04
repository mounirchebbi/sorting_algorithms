#include "sort.h"

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
 * shell_sort - Sort using shell sort algorithm
 * @array: integers
 * @size: size
 */
void shell_sort(int *array, size_t size)
{
	size_t distance, i, j;

	if (array == NULL || size < 2)
		return;

	for (distance = 1; distance < (size / 3);)
		distance = distance * 3 + 1;

	for (; distance >= 1; distance /= 3)
	{
		for (i = distance; i < size; i++)
		{
			j = i;
			while (j >= distance && array[j - distance] > array[j])
			{
				swaper(array + j, array + (j - distance));
				j -= distance;
			}
		}
		print_array(array, size);
	}
}
